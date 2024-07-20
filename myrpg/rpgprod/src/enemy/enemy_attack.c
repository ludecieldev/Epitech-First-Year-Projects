/*
** EPITECH PROJECT, 2024
** enemy_attack.c
** File description:
** handle different attacks from enemy
*/

#include "my_rpg.h"

/**
 * @brief Function to handle the attack of the enemy
 * @param sukuna struct of the enemy
 * @return void
*/
void cleave_attack(enemy_t *sukuna)
{
    int chance;

    chance = rand() % 100;
    if (chance < 10) {
        sukuna->damage = 0;
    } else {
        sukuna->damage = 80;
    }
}

/**
 * @brief Function to handle the attack of the enemy
 * @param sukuna struct of the enemy
 * @return void
*/
void dismantle_attack(enemy_t *sukuna)
{
    int chance;

    chance = rand() % 100;
    if (chance < 90) {
        sukuna->damage = 0;
    } else {
        sukuna->damage = 500;
    }
}
