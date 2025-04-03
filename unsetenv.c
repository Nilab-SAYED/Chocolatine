/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** unsetenv
*/

#include "./include/my.h"

void print_unsetenv_usage(void)
{
    my_putstr_err("unsetenv: Usage: unsetenv VAR\n");
}

void shift_environ(int index)
{
    while (environ[index]) {
        environ[index] = environ[index + 1];
        index++;
    }
}

int my_unsetenv(char **args)
{
    int i = 0;

    if (!args[1]) {
        print_unsetenv_usage();
        return 1;
    }
    while (environ[i]) {
        if (strncmp(environ[i], args[1], strlen(args[1])) == 0 &&
        environ[i][strlen(args[1])] == '=') {
            free(environ[i]);
            shift_environ(i);
            return 0;
        }
        i++;
    }
    return 1;
}
