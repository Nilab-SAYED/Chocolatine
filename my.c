/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** env_utils
*/



#include "./include/my.h"
#include <stdio.h>
#include <stdarg.h>

int my_snprintf(char *str, size_t size, const char *format, ...)
{
    int ret;
    va_list args;

    va_start(args, format);
    ret = vsnprintf(str, size, format, args);
    va_end(args);
    return ret;
}

char *my_strdup(char *str)
{
    char *copy = malloc(strlen(str) + 1);

    if (copy == NULL) {
        return NULL;
    }
    my_strcpy(copy, str);
    return copy;
}

int string_to_number(const char *str)
{
    int num = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            num = num * 10 + (str[i] - '0');
        } else {
            return 0;
        }
        i++;
    }
    return num;
}

void my_puts(const char *str)
{
    while (*str) {
        write(1, str, 1);
        str++;
    }
}

int my_strlen(const char *str)
{
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }
    return len;
}
