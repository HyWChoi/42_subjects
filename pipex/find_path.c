#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// Function to find the full path of a command
char* find_command_path(const char* command, char* const envp[]) {
    const char* path_env = NULL;
    for (int i = 0; envp[i] != NULL; i++) {
        printf("envp[%d]: %s\n", i, envp[i]);
        if (strncmp(envp[i], "PATH=", 5) == 0) {
            path_env = envp[i] + 5; // Skip the "PATH=" part
            break;
        }
    }

    if (path_env == NULL) {
        return NULL; // PATH variable not found
    }

    char* paths = strdup(path_env);
    char* path = strtok(paths, ":");
    while (path != NULL) {
        char* full_path = malloc(strlen(path) + strlen(command) + 2); // +1 for '/', +1 for '\0'
        sprintf(full_path, "%s/%s", path, command);

        if (access(full_path, X_OK) == 0) {
            free(paths);
            return full_path; // Command found
        }

        free(full_path);
        path = strtok(NULL, ":");
    }

    free(paths);
    return NULL; // Command not found
}

// Example usage
int main(int argc, char* argv[], char* const envp[]) {
    char* command = "ls"; // Example command to find
    char* command_path = find_command_path(command, envp);

    if (command_path != NULL) {
        printf("Found command path: %s\n", command_path);
        free(command_path);
    } else {
        printf("Command not found\n");
    }

    return 0;
}
