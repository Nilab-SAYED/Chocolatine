/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** dataframe
*/


#ifndef DATAFRAME_H
    #define DATAFRAME_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>

    #define MAX_COLUMNS 10
    #define MAX_ROWS 100
    #define MAX_LEN 50

typedef enum {
    BOOL,
    INT,
    UINT,
    FLOAT,
    STRING,
    UNDEFINED
} column_type_t;



typedef struct {
    int nb_rows;
    int nb_columns;
    char headers[MAX_COLUMNS][MAX_LEN];
    column_type_t col_types[MAX_COLUMNS];
    char data[MAX_ROWS][MAX_COLUMNS][MAX_LEN];
} dataframe_t;

dataframe_t *df_read_csv(const char *filename, const char *separator);
int df_write_csv(dataframe_t *dataframe, const char *filename);
dataframe_t *df_head(dataframe_t *dataframe, int nb_rows);
dataframe_t *dataframe_tail(dataframe_t *dataframe, int nb_rows);
#endif
