/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** mysh
*/

#include "./include/my.h"

void mysh_loop()
{
    char *input;
    char **args;
    int status = 1;
    char *cmd1;
    char *cmd2;

    while (1) {
        if (isatty(STDIN_FILENO)) {
            write(1, "$>", 2);

        }
        input = readcommand();
        if (input == NULL) {
            break;
        }
        
        if (strchr(input, '|') != NULL) {
            split_command(input, &cmd1, &cmd2);
            execute_pipe(cmd1, cmd2);
        } else {
            args = str_to_word_array(input);
            free(input);
            status = execute_command(args);
            free_str_to_word_array(args);
        }
    }
}

int main(void)
{
    mysh_loop();
    return 0;
}
