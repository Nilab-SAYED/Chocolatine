/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** all_my
*/

#include "./include/my.h"

void my_strncpy(char *dest, const char *src, size_t n)
{
    size_t i = 0;

    while (i < n - 1 && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void my_strncat(char *dest, const char *src, size_t n)
{
    size_t dest_len = 0;
    size_t i = 0;

    while (dest[dest_len] != '\0') {
        dest_len++;
    }
    while (i < n - 1 && src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
}

char *my_strchr(const char str[], char ch)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            return (char *)&str[i];
        }
    }
    return NULL;
}

int is_separator(char ch, const char *separators)
{
    for (; *separators; separators++)
        if (ch == *separators)
            return 1;
    return 0;
}
