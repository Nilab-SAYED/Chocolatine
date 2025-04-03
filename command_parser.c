/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** command_parser
*/

#include "./include/my.h"

int my_isspace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' ||
            c == '\r' || c == '\v' || c == '\f');
}

int count_words(char *input)
{
    int count = 0;
    int in_word = 0;

    while (*input) {
        if (my_isspace(*input)) {
            in_word = 0;
            input++;
            continue;
        }
        if (!in_word) {
            count++;
        }
        in_word = 1;
        input++;
    }
    return count;
}

void my_strcpy(char *des, char *src)
{
    int i;

    if (src == NULL || des == NULL) {
        return;
    }
    for (i = 0; src[i] != '\0'; i++) {
        des[i] = src[i];
    }
    des[i] = '\0';
}
