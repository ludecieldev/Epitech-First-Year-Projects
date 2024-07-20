/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-navy-alexandre.garbe
** File description:
** attacker.c
** Author:
** julienmars
*/

#include "../../include/navy.h"

int check_attack(char *message)
{
    if (message[0] < 'A' || message[0] > 'H' || message[1] < '1'
    || message[1] > '8') {
        mini_printf("Wrong position\n");
        return 84;
    }
    return 0;
}

char *attack(void)
{
    char *message = NULL;
    size_t len = 0;
    ssize_t read = 0;

    while (1) {
        mini_printf("attack: ");
        read = getline(&message, &len, stdin);
        if (read == -1) {
            mini_printf("Erreur lors de la lecture de l'entrée.\n");
            free(message);
            return NULL;
        }
        if (check_attack(message) == 0) {
            break;
        }
    }
    return message;
}

int get_attack(void)
{
    char *message = attack();
    int result = 0;

    if (message == NULL) {
        return 84;
    }
    for (int i = 0; message[i] != '\n'; i++) {
        result = converter(message[i]);
    }
    free(message);
    return result;
}
