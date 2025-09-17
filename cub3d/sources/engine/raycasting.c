/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:46:20 by nakoriko          #+#    #+#             */
/*   Updated: 2025/07/16 15:42:55 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	raycasting(t_game *game)
{
	int	x_screen;
	int	y;

	x_screen = 0;
	while (x_screen < SCREEN_WIDTH)
	{
		reset_ray(game);
		calculate_ray(game, x_screen);
		setup_dda(game);
		perform_dda(game);
		calculate_wall_distance(game);
		calculate_wall_height(game);
		game->texture.tex_num = determine_wall_texture(game);
		calculate_texture_coordinates(game);
		y = game->ray.draw_end;
		while (++y < SCREEN_HEIGHT)
			design_pixel(x_screen, y, game->config.floor_color, game);
		y = 0;
		while (++y < game->ray.draw_start)
			design_pixel(x_screen, y, game->config.ceiling_color, game);
		draw_textured_wall(game, x_screen);
		x_screen++;
	}
}

/*
*Calcola le delta distances e imposta le side distances iniziali
*per il raggio corrente. Determina anche la direzione dei passi (step_x, step_y)
*in base alla direzione del raggio.
*/
void	setup_dda(t_game *game)
{
	t_ray	*ray;

	ray = &game->ray;
	calculate_delta_x_y(game);
	calculate_side_dist_x(game);
	if (ray->ray_dir_y < 0)
	{
		ray->side_dist_y = (game->player.pos_y - ray->map_y)
			* ray->delta_dist_y;
		ray->step_y = -1;
	}
	else
	{
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.pos_y)
			* ray->delta_dist_y;
		ray->step_y = 1;
	}
}

/*
*Confronta side_dist_x e side_dist_y,
*sceglie quale linea attraversare, aggiorna la posizione nella
*griglia e controlla se ha colpito una parete.
*/
void	perform_dda(t_game *game)
{
	t_ray	*ray;

	ray = &game->ray;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->map_x += ray->step_x;
			ray->side_dist_x += ray->delta_dist_x;
			ray->side = 0;
			if (game->map.map_mtx[ray->map_y][ray->map_x] == '1')
				ray->hit = 1;
		}
		else if (ray->side_dist_x >= ray->side_dist_y)
		{
			ray->map_y += ray->step_y;
			ray->side_dist_y += ray->delta_dist_y;
			ray->side = 1;
			if (game->map.map_mtx[ray->map_y][ray->map_x] == '1')
				ray->hit = 1;
		}
	}
}

/**
*Converte la distanza della parete in altezza di pixel sullo schermo.
*Calcola anche i punti di inizio e fine per disegnare la linea verticale.
*/
void	calculate_wall_height(t_game *game)
{
	t_ray	*ray;

	ray = &game->ray;
	ray->line_height = SCREEN_HEIGHT / ray->wall_dist;
	ray->draw_start = (SCREEN_HEIGHT - ray->line_height) / 2;
	ray->draw_end = (SCREEN_HEIGHT + ray->line_height) / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= SCREEN_HEIGHT)
		ray->draw_end = SCREEN_HEIGHT - 1;
}
