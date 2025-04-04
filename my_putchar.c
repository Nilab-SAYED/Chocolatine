/*
** EPITECH PROJECT, 2025
** ChocoGit
** File description:
** my_putchar
*/

#include <unistd.h>

void my_puthchar(char c)
{
    write(1, &c, 1);
}
