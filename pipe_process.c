/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** pipe_process
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void split_command(char *input, char **cmd1, char **cmd2)
{
    *cmd1 = strtok(input, "|");
    *cmd2 = strtok(NULL, "|");
    if (*cmd1) {
        while (**cmd1 == ' ')
            (*cmd1)++;
    }
    if (*cmd2) {
        while (**cmd2 == ' ')
            (*cmd2)++;
    }
}

char **parse_cmnd(char *cmd)
{
    int i = 0;
    char *token;
    char **args = malloc(10 * sizeof(char *));
    if (!args) {
        perror("Memory allocation failed!");
        return NULL;
    }
    token = strtok(cmd, " ");
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
    return args;
}

void execute_pipe(char *cmd1, char *cmd2)
{
    int fd[2];
    pid_t pid1, pid2;
    char **args1, **args2;

    if (pipe(fd) == -1) {
        perror("Pipe failed!");
        exit(1);
    }

    pid1 = fork();
    if (pid1 == -1) {
        perror("Fork failed!");
        exit(1);
    }

    if (pid1 == 0) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        args1 = parse_cmnd(cmd1);
        execve(args1[0], args1, NULL);
        perror("Execve failed!");
        exit(1);
    }

    pid2 = fork();
    if (pid2 == -1) {
        perror("Fork failed!");
        exit(1);
    }

    if (pid2 == 0) {
        dup2(fd[0], STDIN_FILENO);
        close(fd[1]);
        args2 = parse_cmnd(cmd2);
        execve(args2[0], args2, NULL);
        perror("Execve failed!");
        exit(1);
    }
    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}
