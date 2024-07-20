/*
** EPITECH PROJECT, 2024
** N4S-Prod
** File description:
** get_info_lidar
*/

#include "n4s.h"

void check_left(int ratio, n4s_t *n4s)
{
    if (ratio > -500) {
        wheel_dir(n4s, 0.5);
        return;
    }
    if (ratio > -750) {
        wheel_dir(n4s, 0.4);
        return;
    }
    if (ratio > -1000) {
        wheel_dir(n4s, 0.3);
        return;
    }
    if (ratio > -1500) {
        wheel_dir(n4s, 0.2);
        return;
    }
}

void check_right(int ratio, n4s_t *n4s)
{
    if (ratio < 500) {
        wheel_dir(n4s, -0.5);
        return;
    }
    if (ratio < 750) {
        wheel_dir(n4s, -0.4);
        return;
    }
    if (ratio < 1000) {
        wheel_dir(n4s, -0.3);
        return;
    }
    if (ratio < 1250) {
        wheel_dir(n4s, -0.2);
        return;
    }
}

void lidar_interpreter(double *lidar, n4s_t *n4s)
{
    int ratio = lidar[8] - lidar[24];

    if ((lidar[0] == 0 || lidar[31] == 0) && lidar[15] < 200) {
        car_backward(0.2, n4s);
        return;
    }
    if (ratio > 0) {
        check_left(ratio, n4s);
        car_forward(0.2, n4s);
        return;
    }
    if (ratio < 0) {
        check_right(ratio, n4s);
        car_forward(0.2, n4s);
        return;
    }
}
