#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

void execute_command(char *cmd, char *envp[])
{
    char *argv[4];

    argv[0] = "/bin/sh";
    argv[1] = "-c";
    argv[2] = cmd;
    argv[3] = NULL;

    if (execve("/bin/sh", argv, envp) == -1) {
        perror("execve");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[], char *envp[])
{
    int pipefd[2];
    int infile, outfile;
    pid_t pid1, pid2;

    if (argc != 5) {
        fprintf(stderr, "Usage: ./pipex infile cmd1 cmd2 outfile\n");
        return EXIT_FAILURE;
    }

    infile = open(argv[1], O_RDONLY);
    outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (infile == -1 || outfile == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    if (pipe(pipefd) == -1) {
        perror("pipe");
        return EXIT_FAILURE;
    }

    pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        return EXIT_FAILURE;
    }

    if (pid1 == 0) { // Child process 1
        dup2(infile, STDIN_FILENO);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        execute_command(argv[2], envp);
    }

    pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        return EXIT_FAILURE;
    }

    if (pid2 == 0) { // Child process 2
        dup2(pipefd[0], STDIN_FILENO);
        dup2(outfile, STDOUT_FILENO);
        close(pipefd[1]);
        execute_command(argv[3], envp);
    }

    close(pipefd[0]);
    close(pipefd[1]);
    close(infile);
    close(outfile);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return EXIT_SUCCESS;
}
