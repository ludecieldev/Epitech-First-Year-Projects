/*
** EPITECH PROJECT, 2023
** 101pong
** File description:
** paddle_checker
*/

#include "../../lib/my/my.h"

int paddle_checker(coords_t time_b, coords_t time_a, coords_t vector)
{
    double teta, norme;
    double pi = 180/M_PI;

    norme = sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
    if ((time_b.z <= 0 && vector.z >= 0) || (time_b.z >= 0 && vector.z <= 0)){
        teta = (asin(vector.z/ norme) * pi);
        if (teta < 0)
            teta = teta * -1;
        if (teta >= 0 && teta <= 90){
            printf("\nThe incidence angle is:\n%.2f degrees\n", teta);
            return 0;
        }
        if (time_b.x == 0 && time_b.y == 0 && time_b.z == 0 && time_a.x == 0 && time_a.y == 0 && time_a.z == 0){
            teta = 0.00;
            printf("\nThe incidence angle is:\n%.2f degrees\n", teta);
            return 0;
        }
    }
    printf("\nThe ball won't reach the paddle.\n");
    return 0;
    
}