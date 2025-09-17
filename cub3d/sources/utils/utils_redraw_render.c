/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redraw_render.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:42:15 by xhamzall          #+#    #+#             */
/*   Updated: 2025/07/16 15:45:51 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	design_pixel(int x, int y, int color, t_game *game)
{
	char	*pixel;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	pixel = game->img.addr + (y * game->img.size_line + x
			* (game->img.bpp / 8));
	*(unsigned int *)pixel = color;
}

/**
 * Estrae il colore di un pixel specifico da una texture. Gestisce l'accesso
 *ai dati della texture e converte in formato colore utilizzabile
 */
int	get_texture_color(t_game *game, int tex_num, int tex_x, int tex_y)
{
	char	*pxl;
	int		color;
	t_wall	*txtr;

	txtr = &game->wall[tex_num];
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= txtr->width)
		tex_x = txtr->width - 1;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= txtr->height)
		tex_y = txtr->height - 1;
	pxl = txtr->addr + (tex_y * txtr->size_line) + (tex_x * (txtr->bpp / 8));
	color = *(unsigned int *)pxl;
	return (color);
}

/**
* Determina quale texture usare (NORTH/SOUTH/EAST/WEST) in base al lato della
* parete colpito e alla direzione del raggio
*/
int	determine_wall_texture(t_game *game)
{
	t_ray	*ray;

	ray = &game->ray;
	if (ray->side == 0 && ray->ray_dir_x < 0)
		return (EAST_TXTR);
	else if (ray->side == 0 && ray->ray_dir_x > 0)
		return (WEST_TXTR);
	else if (ray->side == 1 && ray->ray_dir_y > 0)
		return (NORTH_TXTR);
	else if (ray->side == 1 && ray->ray_dir_y < 0)
		return (SOUTH_TXTR);
	return (ft_error("Cannot determinate the wall texture"), -1);
}

void	checks_wall(t_texture *texture)
{
	if (texture->wall_x < 0.0)
		texture->wall_x = 0.0;
	if (texture->wall_x >= 1.0)
		texture->wall_x = 0.999;
}
