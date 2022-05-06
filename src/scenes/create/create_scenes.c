/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-adrien.ricou
** File description:
** init_menu
*/

#include "rpg.h"

static int create_menu2(main_game_t *game)
{
    if (!game)
        return EPITECH_ERROR;
    if (init_menu(&game->mnu->settings, MAIN_THEME, SETTINGS_SS,
    (sfIntRect){200, 200, 0, 0}) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_menu(&game->mnu->help_play, MAIN_THEME, SETTINGS_BG,
    (sfIntRect){200, 200, 0, 0}) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_menu(&game->mnu->pause_m, MAIN_THEME, SETTINGS_BG,
    (sfIntRect){200, 200, 0, 0}) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_menu(&game->mnu->skin_m, MAIN_THEME, SKIN_CUS_SS,
    (sfIntRect){200, 200, 0, 0}) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_menu(&game->mnu->keybind_m, MAIN_THEME, MENU_BG,
    (sfIntRect){200, 200, 0, 0}) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}

int create_menus(main_game_t *game)
{
    if (!game)
        return EPITECH_ERROR;
    if (init_menu(&game->mnu->main, MAIN_THEME, MENU_BG,
    (sfIntRect){0, 0, 0, 0}) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_menu(&game->mnu->gameplay, GAME_THEME, INV_SS,
    (sfIntRect){0, 0, 0, 0}) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_menu(&game->mnu->save_m, MAIN_THEME, MENU_BG,
    (sfIntRect){200, 200, 0, 0}) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (create_menu2(game) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}
