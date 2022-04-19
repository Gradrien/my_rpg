/*
** EPITECH PROJECT, 2022
** menu
** File description:
** menu
*/

#ifndef MENU_H_
#define MENU_H_
    #include "csfml.h"
    #include "game_object.h"

    typedef enum {
        UNKNOWN_SCENE = -1,
        MENU_SCENE,
        SETTINGS_SCENE,
        EXIT_SCENE,
        HELP_SCENE,
        GAME_SCENE,
        PAUSE_SCENE
    } scenes_name;

    typedef struct menu_s {
        sfMusic *theme;
        game_object_t *object;
        game_object_t *bg_object;
    } menu_t;

    typedef struct all_menu_s {
        menu_t *main;
        menu_t *scoreboard;
        menu_t *gameplay;
        menu_t *settings;
        menu_t *help_play;
        menu_t *pause_m;
    } mnu_t;

#endif /* !MENU_H_ */