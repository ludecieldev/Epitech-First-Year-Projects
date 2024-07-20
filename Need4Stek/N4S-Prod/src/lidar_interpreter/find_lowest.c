/*
** EPITECH PROJECT, 2024
** N4S-Prod
** File description:
** find_lowest
*/

#include "n4s.h"

int find_lowest_index(double *lidar)
{
    int i = 0;
    int index = 0;
    double lowest = 10000;

    while (lidar[i] != -1) {
        if (lidar[i] < lowest) {
            lowest = lidar[i];
            index = i;
        }
        i++;
    }
    return (index);
}
