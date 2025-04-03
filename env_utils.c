/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** env_utils
*/



#include "./include/my.h"

char **copy_env(void)
{
    int i = 0;
    char **new_env;

    while (environ[i]) {
        i++;
    }
    new_env = malloc((i + 1) * sizeof(char *));
    for (int j = 0; j < i; j++) {
        new_env[j] = my_strdup(environ[j]);
    }
    new_env[i] = NULL;
    return new_env;
}

void free_env(char **env)
{
    for (int i = 0; env[i]; i++)
        free(env[i]);
    free(env);
}

int my_strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

void free_str_to_word_array(char **args)
{
    if (!args)
        return;
    for (int i = 0; args[i]; i++)
        free(args[i]);
    free(args);
}

int my_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i = 0;

    while (i < n && s1[i] && s2[i]) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    if (i < n)
        return (s1[i] - s2[i]);
    return 0;
}
