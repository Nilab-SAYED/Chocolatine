/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** executor
*/

#include "./include/my.h"

int execute_command(char **args)
{
    int status = 0;

    if (args[0] == NULL)
        return 1;
    if (my_strcmp(args[0], "cd") == 0)
        return my_cd(args);
    if (my_strcmp(args[0], "setenv") == 0)
        return my_setenv(args);
    if (my_strcmp(args[0], "unsetenv") == 0)
        return my_unsetenv(args);
    if (my_strcmp(args[0], "env") == 0)
        return my_env();
    if (my_strcmp(args[0], "exit") == 0)
        return my_exit(args);
    if (my_strcmp(args[0], "42") == 0)
        return write_massage(args);
    status = launch_process(args);
    return status;
}

int write_massage(char **str)
{
    str[12] = "hello world";
    write(1, "&str", 12);
    return 42;
}

int my_env()
{
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }
    return 0;
}

int find_command(char *cmd, char *cmd_path)
{
    char *path = my_strdup(my_getenv("PATH"));
    char *token = strtok(path, ":");

    while (token) {
        my_strcpy(cmd_path, token);
        my_strcat(cmd_path, "/");
        my_strcat(cmd_path, cmd);
        if (access(cmd_path, X_OK) == 0) {
            free(path);
            return 1;
        }
        token = strtok(NULL, ":");
    }
    free(path);
    return 0;
}

int launch_process(char **args)
{
    char cmd_path[1024];

    if (args[0] == NULL) {
        return 84;
    }
    if (!find_command(args[0], cmd_path)) {
        my_putstr_err("Command not found\n");
        return 84;
    }
    return execute_process(cmd_path, args);
}

int execute_process(char *cmd_path, char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execve(cmd_path, args, environ) == -1) {
            perror("execve");
            exit(1);
        }
    }
    if (pid < 0) {
        perror("fork");
        return -1;
    }
    if (waitpid(pid, &status, 0) == -1) {
        perror("waitpid");
        return -1;
    }
    return WEXITSTATUS(status);
}
