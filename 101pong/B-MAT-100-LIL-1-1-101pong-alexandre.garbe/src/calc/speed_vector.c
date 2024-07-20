/*
** EPITECH PROJECT, 2023
** 101pong
** File description:
** speed_vector
*/

#include "../../lib/my/my.h"

int speed_vector(coords_t time_a, coords_t time_b, int n)
{
    coords_t vector =  {.x = (time_b.x - time_a.x),
                        .y = (time_b.y - time_a.y),
                        .z = (time_b.z - time_a.z)};
    coords_t vector_n =    {.x = time_b.x + (vector.x * n),
                            .y = time_b.y + (vector.y * n),
                            .z = time_b.z + (vector.z * n)};

    printf("The velocity vector of the ball is:\n(%.2f, %.2f, %.2f)"
    , vector.x, vector.y, vector.z);
    printf("\nAt time t + %d, ball coordinates will be:", n);
    printf("\n(%.2f, %.2f, %.2f)", vector_n.x, vector_n.y, vector_n.z);
    paddle_checker(time_b, time_a, vector);
    return 0;
}
