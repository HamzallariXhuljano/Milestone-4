/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:50:27 by xhamzall          #+#    #+#             */
/*   Updated: 2025/07/16 15:45:46 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * Calcola quanto mi sposto per atraversare una cella
 */
void	calculate_delta_x_y(t_game *game)
{
	t_ray	*ray;

	ray = &game->ray;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

/**
 *side_dist_ distanza dal muro step_ dove sto andando verso sinisra e destra
 */
void	calculate_side_dist_x(t_game *game)
{
	t_ray	*ray;

	ray = &game->ray;
	if (ray->ray_dir_x < 0)
	{
		ray->side_dist_x = (game->player.pos_x - ray->map_x)
			* ray->delta_dist_x;
		ray->step_x = -1;
	}
	else
	{
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.pos_x)
			* ray->delta_dist_x;
		ray->step_x = 1;
	}
}

/*
*ressetta valori ray cosi da avere sempre un raggio pulito
*su cui lavorare gli altri valori vengono sovrascrtitti dalle altre fuznioni
*come setup_data() e calcuate_ray()
*/
void	reset_ray(t_game *game)
{
	t_ray	*ray;

	ray = &game->ray;
	ray->hit = 0;
	ray->side = 0;
}

/*
*Calcola la direzione del raggio da lanciare per la colonna x dello schermo,
*in base alla posizione e direzione del giocatore.
*/
void	calculate_ray(t_game *game, int x)
{
	game->ray.camera_x = (2.0 * x / game->width) - 1.0;
	game->ray.ray_dir_x = game->player.dir_x
		+ game->player.plane_x * game->ray.camera_x;
	game->ray.ray_dir_y = game->player.dir_y
		+ game->player.plane_y * game->ray.camera_x;
	game->ray.map_x = (int)game->player.pos_x;
	game->ray.map_y = (int)game->player.pos_y;
}

/*
*Calcola la distanza perpendicolare alla parete colpita per evitare
*l'effetto fish-eye.
*/
void	calculate_wall_distance(t_game *game)
{
	t_ray	*ray;

	ray = &game->ray;
	if (ray->side == 0)
		ray->wall_dist = (ray->map_x - game->player.pos_x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else if (ray->side == 1)
		ray->wall_dist = (ray->map_y - game->player.pos_y
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
}
