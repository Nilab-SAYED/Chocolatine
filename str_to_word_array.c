/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** mysh
*/

#include "./include/my.h"

static char *allocate_word(char *start)
{
    char *word = malloc(strlen(start) + 1);

    if (!word) {
        perror("malloc failed for word");
        return NULL;
    }
    my_strcpy(word, start);
    return word;
}

void process_word_and_store(char **args, int *position, char *start, char *end)
{
    *end = '\0';
    args[*position] = allocate_word(start);
    if (!args[*position])
        exit(84);
    (*position)++;
}
// first I allocted memory for word array
char **allocate_args(char *input, char **copy)
{
    char **args;

    *copy = my_strdup(input);
    if (!*copy) {
        perror("strdup failed");
        exit(84);
    }
    args = malloc((count_words(*copy) + 1) * sizeof(char *));
    if (!args) {
        perror("malloc failed");
        free(*copy);
        exit(84);
    }
    return args;
}
// split the words 
void split_words(char **args, char *copy, int *position)
{
    char *start = copy;
    char *end = copy;

    while (*end) {
        if (my_isspace(*end)) {
            if (start != end)
                process_word_and_store(args, position, start, end);
            start = end + 1;
        }
        end++;
    }
    if (start != end)
        process_word_and_store(args, position, start, end);
}

char **str_to_word_array(char *input)
{
    char *copy;
    char **args;
    int position = 0;

    if (!input)
        return NULL;
    args = allocate_args(input, &copy);
    split_words(args, copy, &position);
    args[position] = NULL;
    free(copy);
    return args;
}
