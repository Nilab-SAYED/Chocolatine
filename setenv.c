/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** setenv
*/


#include "./include/my.h"

void print_setenv_usage(void)
{
    my_putstr_err("setenv: Usage: setenv VAR VALUE\n");
}

char *create_env_entry(const char *name, const char *value)
{
    char *new_env;
    size_t name_len = strlen(name);
    size_t value_len = strlen(value);

    new_env = malloc(name_len + value_len + 2);
    if (!new_env)
        return NULL;
    strcpy(new_env, name);
    new_env[name_len] = '=';
    strcpy(new_env + name_len + 1, value);
    return new_env;
}

int update_existing_env(const char *name, const char *value)
{
    size_t name_len = strlen(name);
    char *new_env;

    for (int i = 0; environ[i]; i++) {
        if (my_strncmp(environ[i], name, name_len) == 0 &&
        environ[i][name_len] == '=') {
            new_env = create_env_entry(name, value);
            if (!new_env)
                return 1;
            environ[i] = new_env;
            return 0;
        }
    }
    return -1;
}

int add_new_env(const char *name, const char *value)
{
    int i = 0;
    char **new_environ;

    while (environ[i]) {
        i++;
    }
    new_environ = malloc((i + 2) * sizeof(char *));
    if (!new_environ)
        return 1;
    for (int j = 0; j < i; j++)
        new_environ[j] = environ[j];
    new_environ[i] = create_env_entry(name, value);
    if (!new_environ[i])
        return 1;
    new_environ[i + 1] = NULL;
    environ = new_environ;
    return 0;
}

int my_setenv(char **args)
{
    if (!args[1] || !args[2]) {
        print_setenv_usage();
        return 84;
    }
    if (update_existing_env(args[1], args[2]) == 0)
        return 0;
    return add_new_env(args[1], args[2]);
}
