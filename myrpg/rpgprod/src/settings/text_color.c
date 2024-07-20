/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** text_color
*/

#include "my_rpg.h"

/**
 * @brief Function to change color of text in resolution
 * @param rpg struct of rpg and color
 * @return void
*/
void change_text_color_resolutions(my_rpg_t *rpg, sfColor color)
{
    if (rpg->settings->resolution_type == RES_1920_1080_TYPE)
        sfText_setColor(rpg->settings->resolution_texts[0].text, color);
    else
        sfText_setColor(rpg->settings->resolution_texts[0].text, (sfColor){
            INSIDE_TEXT_COLOR});
    if (rpg->settings->resolution_type == RES_1280_720_TYPE)
        sfText_setColor(rpg->settings->resolution_texts[1].text, color);
    else
        sfText_setColor(rpg->settings->resolution_texts[1].text, (sfColor){
            INSIDE_TEXT_COLOR});
    if (rpg->settings->resolution_type == RES_720_480_TYPE)
        sfText_setColor(rpg->settings->resolution_texts[2].text, color);
    else
        sfText_setColor(rpg->settings->resolution_texts[2].text, (sfColor){
            INSIDE_TEXT_COLOR});
}

/**
 * @brief Function to change color of text for fps
 * @param rpg struct of rpg and color
 * @return void
*/
void change_text_color_fps(my_rpg_t *rpg, sfColor color)
{
    if (rpg->settings->fps == 60)
        sfText_setColor(rpg->settings->fps_texts[0].text, color);
    else
        sfText_setColor(rpg->settings->fps_texts[0].text, (sfColor){
            INSIDE_TEXT_COLOR});
    if (rpg->settings->fps == 144)
        sfText_setColor(rpg->settings->fps_texts[1].text, color);
    else
        sfText_setColor(rpg->settings->fps_texts[1].text, (sfColor){
            INSIDE_TEXT_COLOR});
    if (rpg->settings->fps == 240)
        sfText_setColor(rpg->settings->fps_texts[2].text, color);
    else
        sfText_setColor(rpg->settings->fps_texts[2].text, (sfColor){
            INSIDE_TEXT_COLOR});
    if (rpg->settings->fps == 0)
        sfText_setColor(rpg->settings->fps_texts[3].text, color);
    else
        sfText_setColor(rpg->settings->fps_texts[3].text, (sfColor){
            INSIDE_TEXT_COLOR});
}

/**
 * @brief Function to change color of text
 * @param rpg struct of rpg and color
 * @return void
*/
void change_text_color(my_rpg_t *rpg, sfColor color)
{
    if (rpg->settings->fullscreen) {
        sfText_setColor(rpg->settings->fullscreen_texts[0].text, color);
        sfText_setColor(rpg->settings->fullscreen_texts[1].text, (sfColor){
            INSIDE_TEXT_COLOR});
    } else {
        sfText_setColor(rpg->settings->fullscreen_texts[1].text, color);
        sfText_setColor(rpg->settings->fullscreen_texts[0].text, (sfColor){
            INSIDE_TEXT_COLOR});
    }
    if (rpg->settings->vsync) {
        sfText_setColor(rpg->settings->vsync_texts[0].text, color);
        sfText_setColor(rpg->settings->vsync_texts[1].text, (sfColor){
            INSIDE_TEXT_COLOR});
    } else {
        sfText_setColor(rpg->settings->vsync_texts[1].text, color);
        sfText_setColor(rpg->settings->vsync_texts[0].text, (sfColor){
            INSIDE_TEXT_COLOR});
    }
    change_text_color_fps(rpg, color);
    change_text_color_resolutions(rpg, color);
}
