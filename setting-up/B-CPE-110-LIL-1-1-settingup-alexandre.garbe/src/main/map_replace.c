/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-settingup-alexandre.garbe
** File description:
** map_replace
*/

#include "../../lib/my/settingup.h"

char find_min(char a, char b, char c)
{
    char min;

    if (a < b && a < c) {
        min = a;
    } else if (b < c) {
        min = b;
    } else {
        min = c;
    }
    return min;
}

void update_ar_value(char **map, int **ar, int i, int j)
{
    if (i == 0 || j == 0 || map[i][j] == 'o') {
        ar[i][j] = (map[i][j] == '.' ? 1 : 0);
    } else {
        ar[i][j] = (map[i][j] == '.' ? find_min(ar[i - 1][j],\
                    ar[i][j - 1], ar[i - 1][j - 1]) + 1 : 0);
    }
}

void mark_largest_square(values_t *values)
{
    for (int i = values->max_i - values->max_size + 1; \
                                i <= values->max_i; i++) {
        for (int j = values->max_j - values->max_size + 1; \
                                    j <= values->max_j; j++) {
            values->map[i][j] = 'x';
        }
    }
}

void conditional_shorter(int **ar, int i, int j, values_t *values)
{
    if (ar[i][j] > values->max_size) {
        values->max_size = ar[i][j];
        values->max_i = i;
        values->max_j = j;
    }
}

void find_and_mark_largest_square(values_t *values)
{
    int **ar = malloc(values->rows * sizeof(int *));

    for (int i = 0; i < values->rows; i++) {
        ar[i] = malloc(values->cols * sizeof(int));
        for (int j = 0; j < values->cols; j++) {
            update_ar_value(values->map, ar, i, j);
            conditional_shorter(ar, i, j, values);
            }
        }
    if (values->max_i != -1 && values->max_j != -1)
        mark_largest_square(values);
}
