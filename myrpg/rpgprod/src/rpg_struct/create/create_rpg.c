/*
** EPITECH PROJECT, 2024
** create_rpg.c
** File description:
** create struct rpg
*/

#include "my_rpg.h"

/**
 * @brief Function (bool) to create the buttons
 * @param rpg struct of the game
 * @return true
*/
void init_game_components(game_t *game)
{
    if (!game)
        return;
    game->player = init_player();
    game->enemy = init_enemy();
    game->help = init_help();
    game->pnj = init_pnj();
    game->inventory = init_inventory(game->player);
}

bool create_buttons_func(my_rpg_t *rpg)
{
    rpg->menu->buttons_func[PLAY_BUTTON] = &play_func;
    rpg->menu->buttons_func[SETTINGS_BUTTON] = &settings_func;
    rpg->menu->buttons_func[QUIT_BUTTON] = &quit_func;
    if (!rpg->menu->buttons_func[PLAY_BUTTON]
        || !rpg->menu->buttons_func[SETTINGS_BUTTON]
        || !rpg->menu->buttons_func[QUIT_BUTTON])
        return false;
    return true;
}

/**
 * @brief Function to create the game
 * @param void
 * @return game
*/
game_t *create_game(void)
{
    game_t *game = calloc(1, sizeof(game_t) + 1);

    if (game == NULL)
        return NULL;
    game->background = create_sprite("assets/game/new_map.png",
        (sfVector2f){0, 0}, (sfIntRect){0, 0, 564, 890});
    init_game_components(game);
    game->view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    sfView_setCenter(game->view, game->player->pos);
    sfView_zoom(game->view, 0.3);
    game->map = sfImage_createFromFile("assets/game/maptravel.png");
    game->hover = create_sprite("assets/game/tree_hover.png",
        (sfVector2f){0, 0}, (sfIntRect){0, 0, 564, 890});
    if (game->background.sprite == NULL || game->view == NULL || !game->player
        || !game->player->sprite || !game->player->texture || !game->map)
        return NULL;
    return game;
}

/**
 * @brief Function to create the rpg
 * @param void
 * @return rpg
*/
my_rpg_t *create_rpg(void)
{
    my_rpg_t *rpg = calloc(1, sizeof(my_rpg_t) + 1);

    if (rpg == NULL)
        return NULL;
    rpg->screen = create_window_struct(WIDTH, HEIGHT, "MY_RPG");
    rpg->cursor = create_cursor();
    rpg->menu = create_menu();
    SETTINGS = create_settings();
    rpg->loop_value = 0;
    rpg->game = create_game();
    if (!create_texts(rpg) || !create_buttons_func(rpg))
        return NULL;
    if (rpg->screen == NULL || rpg->cursor == NULL || rpg->menu == NULL
        || SETTINGS == NULL || rpg->game == NULL)
        return NULL;
    sf_set_screen(rpg);
    return rpg;
}
