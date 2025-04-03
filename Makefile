##
## EPITECH PROJECT, 2025
## minishell
## File description:
## makefile
##

CC = gcc

CFLAGS	=	-W -Wextra -Wall -g

SRC	=   builtins.c \
		read_command.c \
		command_parser.c \
		env_utils.c \
		executor.c \
		mysh.c \
		my.c \
		str_to_word_array.c \
		all_my.c \
		my_c.c \
		setenv.c \
		unsetenv.c \
		pipe_process.c \


OBJ	=	$(SRC:.c=.o)

NAME = mysh

all	:   $(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)
tests_run:

re	:	fclean all

.PHONY: all clean fclean re
