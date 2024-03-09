/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_pipex.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>	 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/03/08 17:39:55 by hyeonwch		  #+#	#+#			 */
/*   Updated: 2024/03/08 18:19:52 by hyeonwch		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_pipex.h"

t_boolean	check_access(const char *str[])
{
	const char	*file1;
	const char	*file2;
	int		mod;

	mod = R_OK | W_OK;
	file1 = str[1];
	file2 = str[2];
	if (access( file1, mod ) == ERROR)
	{
		perror("file1 is not exist or permission denied.");
		return (FALSE);
	}
	if (access( file2, mod ) == ERROR)
	{
		perror("file2 is not exist or permission denied.");
		return (FALSE);
	}
	return (TRUE);
}

t_boolean	check_argc(int argc)
{
	if (argc != 5)
	{
		perror("Usage: ./pipex file1 cmd1 cmd2 file2");
		return (FALSE);
	}
	return (TRUE);
}

t_boolean	check_open(int fd)
{
	if (fd == ERROR)
	{
		perror("open error");
		return (FALSE);
	}
	return (TRUE);
}

t_boolean	check_pipe(int *pipefd)
{
	pipe(pipefd);
	if (*pipefd == ERROR || *(pipefd + 1) == ERROR)
	{
		perror("pipe error");
		return (FALSE);
	}
	return (TRUE);
}

t_boolean	check_fork(pid_t *pid)
{
	*pid = fork();
	if (*pid == ERROR)
	{
		perror("fork error");
		return (FALSE);
	}
	return (TRUE);
}

void	execute_command(const char *cmd, const char *envp[], char *path[])
{
	char	**argv;

	argv = ft_split(cmd, ' ');
	if (execve(argv[0], argv, envp) == ERROR)
	{
		perror("execve error");
		exit(0);
	}
}
char	**find_path(char *envp[])
{
	char	*path;

	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	path = *envp + 5;
	return (ft_split(path, ':'));
}

int	main(int argc, const char *argv[], const char *envp[])
{
	int	pipefd[2];
	int	infile;
	int	outfile;
	pid_t	pid1;
	pid_t	pid2;
	char	**path;

	check_argc(argc);
	check_access(argv);
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	path = find_path((char **)envp);
	if (!check_open(infile) || !check_open(outfile))
		return (0);
	if (!check_pipe(pipefd))
		return (0);
	if (!check_fork(&pid1))
		return (0);
	if (pid1 > 0)
	{
		dup2(outfile, STDOUT_FILENO); // replace the standard output with the pipe output
		dup2(infile, STDIN_FILENO); // replace the standard input with the file input
		close(pipefd[0]); // close the read end of the pipe
		execute_command(argv[2], envp, path); // execute the second command
	}
	if (!check_fork_error(&pid2))
		return (0);
	if (pid2 > 0)
	{
		dup2(infile, STDIN_FILENO); // replace the standard input with the pipe input
		dup2(pipefd[1], STDOUT_FILENO); // replace the standard output with the pipe output
		close(pipefd[0]); // close the read end of the pipe
		execute_command(argv[3], envp, path); // execute the first command
	}
	close(pipefd[0]);
	close(pipefd[1]);
	close(infile);
	close(outfile);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return 0;
}
