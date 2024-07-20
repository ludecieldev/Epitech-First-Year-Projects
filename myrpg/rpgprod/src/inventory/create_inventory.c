/*
** EPITECH PROJECT, 2024
** rpg-prod
** File description:
** init_inventory
*/

#include "my_rpg.h"

static void toggle_inventory_gem_display(inventory_t *inv)
{
    sfVector2f player_pos;
    sfVector2f inventory_pos;

    if (!inv || !inv->player)
        return;
    inv->is_gem_picked = !inv->is_gem_picked;
    if (inv->is_gem_picked) {
        player_pos = inv->player->pos;
        inventory_pos.x = player_pos.x + 50;
        inventory_pos.y = player_pos.y;
        sfSprite_setPosition(inv->sprite_invgem, inventory_pos);
    } else {
        sfSprite_setPosition(inv->sprite_invgem, (sfVector2f){-1000, -1000});
    }

}

static void toggle_inventory_skull_display(inventory_t *inv)
{
    sfVector2f player_pos;
    sfVector2f inventory_pos;

    if (!inv || !inv->player)
        return;
    inv->is_skull_picked = !inv->is_skull_picked;
    if (inv->is_skull_picked) {
        player_pos = inv->player->pos;
        inventory_pos.x = player_pos.x + 50;
        inventory_pos.y = player_pos.y;
        sfSprite_setPosition(inv->sprite_invskull, inventory_pos);
    } else {
        sfSprite_setPosition(inv->sprite_invskull, (sfVector2f){-1000, -1000});
    }
}

static void toggle_inventory_both_display(inventory_t *inv)
{
    sfVector2f player_pos;
    sfVector2f inventory_pos;

    if (!inv || !inv->player)
        return;
    inv->is_both_picked = !inv->is_both_picked;
    if (inv->is_both_picked) {
        player_pos = inv->player->pos;
        inventory_pos.x = player_pos.x + 50;
        inventory_pos.y = player_pos.y;
        sfSprite_setPosition(inv->sprite_invboth, inventory_pos);
    } else {
        sfSprite_setPosition(inv->sprite_invboth, (sfVector2f){-1000, -1000});
    }
}

void toggle_inv_empty_display(inventory_t *inv)
{
    sfVector2f player_pos;
    sfVector2f inventory_pos;

    if (!inv || !inv->player)
        return;
    inv->is_visible = !inv->is_visible;
    if (inv->is_visible) {
        player_pos = inv->player->pos;
        inventory_pos.x = player_pos.x + 50;
        inventory_pos.y = player_pos.y;
        sfSprite_setPosition(inv->sprite_inv, inventory_pos);
    } else {
        sfSprite_setPosition(inv->sprite_inv, (sfVector2f){-1000, -1000});
    }
}

void toggle_inventory_display(inventory_t *inv)
{
    if (inv->is_both_picked)
        toggle_inventory_both_display(inv);
    if (inv->is_gem_picked)
        toggle_inventory_gem_display(inv);
    if (inv->is_skull_picked)
        toggle_inventory_skull_display(inv);
    if (inv->is_empty)
        toggle_inv_empty_display(inv);
}

void set_func_for_inv(inventory_t *inv)
{
    sfSprite_setTexture(inv->sprite_inv, inv->texture_inv, sfTrue);
    sfSprite_setTextureRect(inv->sprite_inv, inv->rect);
    sfSprite_setPosition(inv->sprite_inv, (sfVector2f){inv->pos.x, inv->pos.y});
    sfSprite_setTexture(inv->sprite_invgem, inv->texture_invgem, sfTrue);
    sfSprite_setTextureRect(inv->sprite_invgem, inv->rect);
    sfSprite_setPosition(inv->sprite_invgem, (sfVector2f){inv->pos.x, inv->pos.y});
    sfSprite_setTexture(inv->sprite_invskull, inv->texture_invskull, sfTrue);
    sfSprite_setTextureRect(inv->sprite_invskull, inv->rect);
    sfSprite_setPosition(inv->sprite_invskull, (sfVector2f){inv->pos.x, inv->pos.y});
    sfSprite_setTexture(inv->sprite_invboth, inv->texture_invboth, sfTrue);
    sfSprite_setTextureRect(inv->sprite_invboth, inv->rect);
    sfSprite_setPosition(inv->sprite_invboth, (sfVector2f){inv->pos.x, inv->pos.y});
}

void sprite_init(inventory_t *inv)
{
    inv->texture_inv = sfTexture_createFromFile("assets/inv/inv.png", NULL);
    inv->sprite_inv = sfSprite_create();
    inv->texture_invgem = sfTexture_createFromFile("assets/inv/gem.png", NULL);
    inv->sprite_invgem = sfSprite_create();
    inv->texture_invskull = sfTexture_createFromFile("assets/inv/skull.png", NULL);
    inv->sprite_invskull = sfSprite_create();
    inv->texture_invboth = sfTexture_createFromFile("assets/inv/both.png", NULL);
    inv->sprite_invboth = sfSprite_create();
}

/**
 * @brief Create an inventory object
 * @param void
 * @return inventory_t
*/
inventory_t *init_inventory(player_t *player)
{
    inventory_t *inv = calloc(1, sizeof(inventory_t) + 1);

    if (inv == NULL)
        return NULL;
    inv->player = player;
    sprite_init(inv);
    inv->rect = (sfIntRect){0, 0, 80, 79};
    inv->pos = (sfVector2f){245, 800};
    inv->is_visible = false;
    inv->is_both_picked = false;
    inv->is_gem_picked = false;
    inv->is_skull_picked = false;
    inv->is_empty = true;
    set_func_for_inv(inv);
    return inv;
}
