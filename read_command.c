/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** read_command
*/

#include "./include/my.h"

char *readcommand(void)
{
    char *input = NULL;
    size_t bufsize = 0;
    ssize_t len = getline(&input, &bufsize, stdin);

    if (len == -1) {
        free(input);
        return NULL;
    }
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    return input;
}
