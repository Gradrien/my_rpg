/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player_collision
*/

#include "rpg.h"

static bool detect_obstacle_collision(main_game_t *game, sfFloatRect hitbox,
sfVector2f next)
{
    obstacle_t *tmp = NULL;

    if (!game->map->obstacle)
        return 0;
    tmp = game->map->obstacle;
    while (tmp != NULL) {
        hitbox = tmp->hitbox;
        hitbox.left = tmp->hitbox.left + next.x;
        hitbox.top = tmp->hitbox.top + next.y;
        if (sfFloatRect_intersects(&hitbox, &game->player->hitbox, NULL))
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

static bool detect_speobstacle_collision(main_game_t *game, sfFloatRect hitbox,
sfVector2f next)
{
    speobstacle_t *spetmp = NULL;

    if (!game->map->speobstacle)
        return 0;
    spetmp = game->map->speobstacle;
    while (spetmp != NULL) {
        hitbox = spetmp->hitbox;
        hitbox.left = spetmp->hitbox.left + next.x;
        hitbox.top = spetmp->hitbox.top + next.y;
        if (sfFloatRect_intersects(&hitbox, &game->player->hitbox, NULL) &&
        spetmp->hp > 0)
            return 1;
        spetmp = spetmp->next;
    }
    return 0;
}

bool obstacle_collision(main_game_t *game, sfVector2f next)
{
    sfFloatRect hitbox = {0, 0, 0, 0};

    if (detect_obstacle_collision(game, hitbox, next))
        return 1;
    if (detect_speobstacle_collision(game, hitbox, next))
        return 1;
    return 0;
}

bool mob_collision(main_game_t *game, sfVector2f next)
{
    mobe_t *tmp = game->map->mobe;
    sfFloatRect hitbox = {0, 0, 0, 0};

    while (tmp->next != NULL) {
        hitbox = tmp->hitbox;
        hitbox.left = tmp->hitbox.left + next.x;
        hitbox.top = tmp->hitbox.top + next.y;
        if (sfFloatRect_intersects(&hitbox, &game->player->hitbox, NULL)) {
            return (true);
        }
        tmp = tmp->next;
    }
    return (false);
}
