##
## EPITECH PROJECT, 2025
## minishell
## File description:
## makefile
##

NAME	=	libphoenix.a

SRC	=   dataframe_read.c \
		dataframe_write.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wextra -Wall

all	:   $(NAME)

%.o: %.c

	gcc -c $< -o $@

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all