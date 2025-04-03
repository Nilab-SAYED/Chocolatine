/*
** EPITECH PROJECT, 2025
** minishell_one
** File description:
** my header
*/

#ifndef MYSH_H
    #define MYSH_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/wait.h>

extern char **environ;
int string_to_number(const char *str);
void print_unsetenv_usage(void);
int my_putstr(const char *str);
void my_puts(const char *str);
int my_strlen(const char *str);
void my_putchar(char c);
char *strtok(char *str, const char *delim);
void mysh_loop(void);
char **parse_command(char *input);
int my_snprintf(char *str, size_t size, const char *format, ...);
char *my_strdup(char *str);
int execute_command(char **args);
int launch_process(char **args);
char **parse_input(char *input);
int count_words(char *input);
int my_isspace(char c);
void free_str_to_word_array(char **args);
char **str_to_word_array(char *input);
int my_cd(char **args);
int my_env(void);
int my_setenv(char **args);
int my_unsetenv(char **args);
int my_exit(char **args);
char *readcommand(void);
char **copy_env(void);
void free_env(char **env);
void my_strcpy(char *dest, char *src);
char *my_strcat(char *dest, const char *src);
int my_strcmp(const char *str1, const char *str2);
int execute_process(char *cmd_path, char **args);
void my_putstr_err(const char *str);
char *my_getenv(const char *name);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *my_strchr(const char str[], char ch);
char **parse_cmnd(char *cmd);
void split_command(char *input, char **cmd1, char **cmd2);
void execute_pipe(char *cmd1, char *cmd2);
int write_massage(char **str);


#endif
