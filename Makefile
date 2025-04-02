##
## EPITECH PROJECT, 2025
## minishell
## File description:
## makefile
##

NAME	=	cuddle

SRC	=   ./libcaddle/dataframe_read.c \
		./libcaddle/dataframe_write.c \
		main.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wextra -Wall

all	:   $(NAME)

%.o: %.c

	gcc -c $< -o $@

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)
	chmod +x $(NAME) 
clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all