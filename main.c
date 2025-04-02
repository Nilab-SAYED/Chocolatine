/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** main
*/

#include "dataframe.h"

int main(void)
{
    dataframe_t *df = df_read_csv("data.csv", NULL);

    if (!df) {
        printf("Error reading CSV file.\n");
        return 84;
    }
}
