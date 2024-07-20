/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-alexandre.garbe
** File description:
** test_one.c
** Author:
** ludeciel
*/

# include <criterion/criterion.h>
# include "../include/sokoban.h"

Test(sokoban, check_player_position)
{
    struct sokoban_map *map;
    struct position *pos;
    map = make_map_from_string( "##########\n"\
                                "#         #\n"\
                                "#         #\n"\
                                "# PXO   ###\n"\
                                "#         #\n"\
                                "# OX      #\n"\
                                " ##########\n") ;
    pos = get_player_position(map);
    cr_assert_neq(pos, NULL);
    cr_assert_eq(pos->x, 2);
    cr_assert_eq(pos->y, 3);
    free(pos);
    free_map(map);
}
