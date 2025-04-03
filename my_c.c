/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** my_c
*/

#include "./include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return i;
}

char *my_strcat(char *dest, const char *src)
{
    char *ptr = dest;

    while (*ptr != '\0') {
        ptr++;
    }
    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0';
    return dest;
}
