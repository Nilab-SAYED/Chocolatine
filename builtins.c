/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** builtins
*/


#include "./include/my.h"

void my_putstr_err(const char *str)
{
    while (*str)
        write(2, str++, 1);
}

int my_cd(char **args)
{
    char *old_pwd = my_strdup(my_getenv("PWD"));
    char cwd[1024];
    char *setenv_args[3];

    if (!args[1] || my_strcmp(args[1], "~") == 0) {
        chdir(getenv("HOME"));
    } else if (my_strcmp(args[1], "-") == 0) {
        chdir(getenv("OLDPWD"));
    } else if (chdir(args[1]) != 0) {
        perror("cd");
    }
    getcwd(cwd, sizeof(cwd));
    setenv_args[0] = "PWD";
    setenv_args[1] = cwd;
    setenv_args[2] = NULL;
    my_setenv(setenv_args);
    setenv_args[0] = "OLDPWD";
    setenv_args[1] = old_pwd;
    my_setenv(setenv_args);
    free(old_pwd);
    return 0;
}

char *my_getenv(const char *name)
{
    size_t len;

    len = my_strlen(name);
    for (int i = 0; environ[i]; i++) {
        if (my_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
            return environ[i] + len + 1;
    }
    return NULL;
}

int my_exit(char **args)
{
    int exit_code = 0;

    if (args[1] != NULL) {
        exit_code = string_to_number(args[1]);
    }
    free_str_to_word_array(args);
    exit(exit_code);
}
