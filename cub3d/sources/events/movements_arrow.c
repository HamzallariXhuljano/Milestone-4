/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_arrow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 23:18:00 by xhamzall          #+#    #+#             */
/*   Updated: 2025/07/16 15:43:31 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 *Ad ogni rotazione normalizza i vettori a finche siano perpendicolari
 *evita effetto stretching dell'immagine quando si ruota la telecamera.
 *-normalizza il vettore della direzione giocatore
 *rimuove la componetne paralela alla telecamera
 *normalizza la il vettoe della telecamera
 */
void	normalize_vectors(t_game *game)
{
	double		dir_ln;
	double		plane_ln;
	double		dot_product;
	t_player	*plyr;

	plyr = &game->player;
	dir_ln = sqrt(plyr->dir_x * plyr->dir_x + plyr->dir_y * plyr->dir_y);
	if (dir_ln > 0.001)
	{
		plyr->dir_x /= dir_ln;
		plyr->dir_y /= dir_ln;
	}
	dot_product = plyr->dir_x * plyr->plane_x + plyr->dir_y * plyr->plane_y;
	plyr->plane_x -= dot_product * plyr->dir_x;
	plyr->plane_y -= dot_product * plyr->dir_y;
	plane_ln = sqrt(plyr->plane_x * plyr->plane_x + plyr->plane_y
			* plyr->plane_y);
	if (plane_ln > 0.001)
	{
		plyr->plane_x = plyr->plane_x / plane_ln * 0.66;
		plyr->plane_y = plyr->plane_y / plane_ln * 0.66;
	}
}

void	left_rotate(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	angle = -game->player.rot_speed;
	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(angle)
		- game->player.dir_y * sin(angle);
	game->player.dir_y = old_dir_x * sin(angle)
		+ game->player.dir_y * cos(angle);
	game->player.plane_x = game->player.plane_x * cos(game->player.rot_speed)
		- game->player.plane_y * sin(game->player.rot_speed);
	game->player.plane_y = old_plane_x * sin(angle)
		+ game->player.plane_y * cos(angle);
	normalize_vectors(game);
}

void	right_rotate(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	angle = game->player.rot_speed;
	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(angle)
		- game->player.dir_y * sin(angle);
	game->player.dir_y = old_dir_x * sin(angle)
		+ game->player.dir_y * cos(angle);
	game->player.plane_x = game->player.plane_x * cos(angle)
		+ game->player.plane_y * sin(angle);
	game->player.plane_y = old_plane_x * sin(angle)
		+ game->player.plane_y * cos(angle);
	normalize_vectors(game);
}
