##
## EPITECH PROJECT, 2025
## minishell
## File description:
## makefile
##

CC = gcc

CFLAGS	=	-W -Wextra -Wall -g

SRC	=   my_putchar.c \


OBJ	=	$(SRC:.c=.o)

NAME = myputchar

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
