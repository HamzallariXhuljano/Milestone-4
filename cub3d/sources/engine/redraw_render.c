/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:11:13 by nakoriko          #+#    #+#             */
/*   Updated: 2025/07/16 15:43:14 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * questa funzione e stata spostata dentro raycasting
 */
void	ft_floor_celling_render(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	while (x < game->width)
	{
		y = game->height / 2;
		while (++y < game->height)
			design_pixel(x, y, game->config.floor_color, game);
		y = -1;
		while (++y < game->height / 2)
			design_pixel(x, y, game->config.ceiling_color, game);
		x++;
	}
}

void	render_scene(t_game *game)
{
	raycasting(game);
}

int	ft_rerender(t_game *game)
{
	if (!game->img.ptr)
	{
		game->img.ptr = mlx_new_image(game->mlx,
				game->width, game->height);
		if (!game->img.ptr)
			return (ft_error("Mlx_new_image failed"));
	}
	if (!game->img.addr)
	{
		game->img.addr = mlx_get_data_addr (game->img.ptr,
				&game->img.bpp, &game->img.size_line,
				&game->img.endian);
		if (!game->img.addr)
			return (ft_error("Mlx_get_data_addr failed"));
	}
	render_scene(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, 0, 0);
	return (0);
}

/**
 * Calcola il punto esatto dove il raggio ha colpito la parete (wall_x)
 * converte questo in coordinate texture (tex_x). Calcola anche lo step per
 * il texture mapping verticale.
 */
void	calculate_texture_coordinates(t_game *game)
{
	t_ray		*ray;
	t_texture	*texture;
	t_wall		*tex_wall;

	ray = &game->ray;
	texture = &game->texture;
	tex_wall = &game->wall[texture->tex_num];
	if (ray->side == 0)
		texture->wall_x = game->player.pos_y + ray->wall_dist * ray->ray_dir_y;
	else if (ray->side == 1)
		texture->wall_x = game->player.pos_x + ray->wall_dist * ray->ray_dir_x;
	texture->wall_x = texture->wall_x - floor(texture->wall_x);
	checks_wall(texture);
	texture->tex_x = (int)(texture->wall_x * tex_wall->width);
	if (texture->tex_x < 0)
		texture->tex_x = 0;
	if (texture->tex_x >= tex_wall->width)
		texture->tex_x = tex_wall->width;
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		texture->tex_x = tex_wall->width - texture->tex_x - 1;
	texture->step = (double)tex_wall->height / ray->line_height;
	texture->tex_pos = ((double)ray->draw_start - (double)SCREEN_HEIGHT / 2
			+ (double)ray->line_height / 2) * texture->step;
}

/**
 * Disegna una linea verticale texturizzata per la colonna x dello schermo.
 * Per ogni pixel della linea, preleva il colore
 * corretto dalla texture e lo disegna.
 */
void	draw_textured_wall(t_game *game, int x)
{
	int			y;
	int			color;
	t_texture	*texture;

	texture = &game->texture;
	y = game->ray.draw_start;
	while (y < game->ray.draw_end)
	{
		texture->tex_y = (int)texture->tex_pos;
		color = get_texture_color(game, texture->tex_num,
				texture->tex_x, texture->tex_y);
		design_pixel(x, y, color, game);
		texture->tex_pos += texture->step;
		y++;
	}
}
