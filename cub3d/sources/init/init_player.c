/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 02:02:52 by xhamzall          #+#    #+#             */
/*   Updated: 2025/07/16 15:43:47 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	init_player(t_game *game)
{
	game -> player.pos_x = (double)game->map.player_x + 0.5;
	game -> player.pos_y = (double)game->map.player_y + 0.5;
	set_player_dir(game, game->map.player_dir);
	set_camera_plane(game);
	game->player.move_speed = MOVE_SPEED;
	game->player.rot_speed = ROT_SPEED;
	return (0);
}

/**
 * Imposta la direzione del player basandosi sul carattere trovato nella mappa
 * carattere direzione ('N', 'S', 'E', 'W')
 */
void	set_player_dir(t_game *game, char dir)
{
	if (dir == 'N')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = -1.0;
	}
	else if (dir == 'S')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = 1.0;
	}
	else if (dir == 'E')
	{
		game->player.dir_x = 1.0;
		game->player.dir_y = 0.0;
	}
	else if (dir == 'W')
	{
		game->player.dir_x = -1.0;
		game->player.dir_y = 0.0;
	}
}

/**
 * Imposta il piano della camera per creare il field of view
 * Il piano della camera deve essere perpendicolare alla direzione
 * La lunghezza del piano determina il FOV (circa 66 gradi)
 */
void	set_camera_plane(t_game *game)
{
	if (game->map.player_dir == 'N')
	{
		game->player.plane_x = 0.66;
		game->player.plane_y = 0.0;
	}
	else if (game->map.player_dir == 'S')
	{
		game->player.plane_x = -0.66;
		game->player.plane_y = 0.0;
	}
	else if (game->map.player_dir == 'E')
	{
		game->player.plane_x = 0.0;
		game->player.plane_y = 0.66;
	}
	else if (game->map.player_dir == 'W')
	{
		game->player.plane_x = 0.0;
		game->player.plane_y = -0.66;
	}
}
