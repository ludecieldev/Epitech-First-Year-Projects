/*
** EPITECH PROJECT, 2023
** 101pong
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
        #include <stdio.h>
        #include <stdlib.h>
        #include <math.h>

typedef struct coords
{
    double x;
    double y;
    double z;
} coords_t;

//src/calc
int speed_vector(coords_t time_a, coords_t time_b, int n);
int paddle_checker(coords_t time_b, coords_t time_a, coords_t vector);
//src/main
int is_a_recievable_charactere(char c);
int main(int ac, char **av);
int pong101(int ac, char **av);
int errorcase(int ac, char **av);

    #endif /* !MY_H_ */
