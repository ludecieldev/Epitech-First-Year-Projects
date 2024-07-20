/*
** EPITECH PROJECT, 2024
** N4S-Prod
** File description:
** n4s
*/

#ifndef N4S_H_
    #define N4S_H_
    #include "include.h"
    #include "lib.h"

//STRUCT
typedef struct s_n4s {
    char *str;
    int fd;
    double *lidar;
    int speed;
    int direction;
    int speed_max;
    int speed_min;
    int simtime;
}n4s_t;
//SRC
void start_simulation(n4s_t *n4s);
char *get_next_line(int fd);
void stop_simulation(n4s_t *n4s);
void car_forward(float speed, n4s_t *n4s);
void car_backward(float speed, n4s_t *n4s);
void wheel_dir(n4s_t *n4s, float direction);
void get_info_lidar(n4s_t *n4s);
void lidar_interpreter(double *lidar, n4s_t *n4s);
#endif /* !N4S_H_ */
