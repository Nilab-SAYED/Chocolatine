/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** dataframe_write
*/


#include "../dataframe.h"

void write_cell(FILE *file, const char *cell, int is_last_column)
{
    fprintf(file, "%s", cell);
    if (!is_last_column) {
        fprintf(file, ",");
    } else {
        fprintf(file, "\n");
    }
}

// Function to write a full row of data (delegates the cell writing)
void write_row(FILE *file, char data[MAX_COLUMNS][MAX_LEN], int nb_columns)
{
    for (int j = 0; j < nb_columns; j++) {
        write_cell(file, data[j], j == nb_columns - 1);
    }
}

// Function to write the DataFrame to a CSV file
int df_write_csv(dataframe_t *dataframe, const char *filename)
{
    FILE *file = fopen(filename, "w");

    if (!file)
        return 84;
    for (int i = 0; i < dataframe->nb_columns; i++) {
        write_cell(file, dataframe->headers[i],
            i == dataframe->nb_columns - 1);
    }
    for (int i = 0; i < dataframe->nb_rows; i++) {
        write_row(file, dataframe->data[i], dataframe->nb_columns);
    }
    fclose(file);
    return 0;
}
