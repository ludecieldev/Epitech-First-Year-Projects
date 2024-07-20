/*
** EPITECH PROJECT, 2024
** attack_player.c
** File description:
** handle different attacks from player
*/

#include "my_rpg.h"

/**
 * @brief Function to handle the attack (blue) of the player
 * @param gojo struct of the player
 * @return void
*/
void blue_attack(player_t *gojo)
{
    int chance;

    chance = rand() % 100;
    if (chance < 10) {
        gojo->stats[DAMAGE] = 0;
    } else {
        gojo->stats[DAMAGE] = 70;
    }
    gojo->stats[MANA] -= 15;
}

/**
 * @brief Function to handle the attack (red) of the player
 * @param gojo struct of the player
 * @return void
*/
void red_attack(player_t *gojo)
{
    int chance;

    chance = rand() % 100;
    if (chance < 50) {
        gojo->stats[DAMAGE] = 0;
    } else {
        gojo->stats[DAMAGE] = 140;
    }
    gojo->stats[MANA] -= 30;
}

/**
 * @brief Function to handle the attack (purple) of the player
 * @param gojo struct of the player
 * @return void
*/
void purple_attack(player_t *gojo)
{
    int chance;

    chance = rand() % 100;
    if (chance < 90) {
        gojo->stats[DAMAGE] = 0;
    } else {
        gojo->stats[DAMAGE] = 500;
    }
    gojo->stats[MANA] -= 70;
}
