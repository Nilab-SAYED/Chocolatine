/*
** EPITECH PROJECT, 2025
** ChocoGit
** File description:
** my_putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int main(void)
{
    my_putchar('a');
    return 0;
}
