/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** fps_settings
*/

#include "rpg.h"

int manage_fps_minus(main_game_t *game, sfVector2i mouse_pos)
{
    if (button_is_clicked(game->btn->sml->minus_b, mouse_pos) == true
        && game->settings->fps > MIN_FPS) {
        game->settings->fps -= FPS_OFFSET;
        sfRenderWindow_setFramerateLimit(game->w, game->settings->fps);
    }
    return EXIT_SUCCESS;
}

int manage_fps_plus(main_game_t *game, sfVector2i mouse_pos)
{
    if (button_is_clicked(game->btn->sml->plus_b, mouse_pos) == true
        && game->settings->fps < MAX_FPS) {
        game->settings->fps += FPS_OFFSET;
        sfRenderWindow_setFramerateLimit(game->w, game->settings->fps);
    }
    manage_fps_minus(game, mouse_pos);
    return EXIT_SUCCESS;
}

int manage_reso_minus(main_game_t *game, sfVector2i mouse_pos)
{
    if (button_is_clicked(game->btn->sml->minus_r_b, mouse_pos) == true
        && game->settings->res_x > MIN_W_X) {
        int x = game->settings->res_x;
        int new_y = ((x - 960 / 2) * game->settings->res_y) / x;
        game->settings->res_x -= 960 / 2;
        game->settings->res_y = new_y;
        x -= 960 / 2;
        sfRenderWindow_setSize(game->w, (sfVector2u){x, new_y});
        sfView_setSize(game->game_view, (sfVector2f){x, new_y});
        sfView_setSize(game->basic_view, (sfVector2f){x, new_y});
    }
    return EXIT_SUCCESS;
}

int manage_reso_plus(main_game_t *game, sfVector2i mouse_pos)
{
    if (button_is_clicked(game->btn->sml->plus_r_b, mouse_pos) == true
        && game->settings->res_x < MAX_W_X) {
        int x = game->settings->res_x;
        int new_y = ((x + 960 / 2) * game->settings->res_y) / x;
        game->settings->res_x += 960 / 2;
        game->settings->res_y = new_y;
        x += 960 / 2;
        sfRenderWindow_setSize(game->w, (sfVector2u){x, new_y});
        sfView_setSize(game->game_view, (sfVector2f){x, new_y});
        sfView_setSize(game->basic_view, (sfVector2f){x, new_y});
    }
    manage_reso_minus(game, mouse_pos);
    return EXIT_SUCCESS;
}
