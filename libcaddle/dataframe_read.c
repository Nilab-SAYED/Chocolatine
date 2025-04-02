/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** dataframe
*/


#include "../dataframe.h"

dataframe_t *init_df(void)
{
    dataframe_t *df = malloc(sizeof(dataframe_t));

    df->nb_rows = 0;
    df->nb_columns = 0;
    return df;
}

void process_header(dataframe_t *df, char *line, const char *sep)
{
    char *token = strtok(line, sep);
    int col = 0;

    while (token && col < MAX_COLUMNS) {
        strcpy(df->headers[col++], token);
        token = strtok(NULL, sep);
    }
    df->nb_columns = col;
}

void process_row(dataframe_t *df, char *line, const char *sep)
{
    char *token = strtok(line, sep);
    int col = 0;

    while (token && col < MAX_COLUMNS) {
        strcpy(df->data[df->nb_rows][col++], token);
        token = strtok(NULL, sep);
    }
    df->nb_rows++;
}

dataframe_t *df_read_csv(const char *filename, const char *sep)
{
    FILE *file;
    dataframe_t *df;
    char line[1024];
    int row = 0;

    sep = sep ?: ",";
    file = fopen(filename, "r");
    if (!file)
        return NULL;
    df = init_df();
    while (fgets(line, sizeof(line), file) && df->nb_rows < MAX_ROWS) {
        if (row == 0)
            process_header(df, line, sep);
        else
            process_row(df, line, sep);
        row++;
    }
    fclose(file);
    return df;
}
