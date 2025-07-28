/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:19:17 by nakoriko          #+#    #+#             */
/*   Updated: 2025/07/16 15:43:51 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	init_image(t_game *game, int width, int height)
{
	game->img.ptr = mlx_new_image(game->mlx, width, height);
	if (!game->img.ptr)
		return (ft_error("Mlx_new_image failed"));
	game->img.addr = mlx_get_data_addr (game->img.ptr,
			&game->img.bpp, &game->img.size_line,
			&game->img.endian);
	if (!game->img.addr)
		return (ft_error("Mlx_get_data_addr failed"));
	return (0);
}

int	load_xpm(t_game *game, int i, char *path)
{
	game->wall[i].ptr = mlx_xpm_file_to_image(game->mlx,
			path, &game->wall[i].width, &game->wall[i].height);
	if (!game->wall[i].ptr)
		return (ft_error("Failed mlx_xpm_file_to image"));
	game->wall[i].addr = mlx_get_data_addr(game->wall[i].ptr,
			&game->wall[i].bpp, &game->wall[i].size_line,
			&game->wall[i].endian);
	if (!game->wall[i].addr)
		return (ft_error("Failed mlx_get_data_addr for wall"));
	return (0);
}

int	ft_init_textures(t_game *game)
{
	int	i;

	i = -1;
	if (load_xpm(game, ++i, game->config.no_texture) != 0)
		return (1);
	if (load_xpm(game, ++i, game->config.so_texture) != 0)
		return (1);
	if (load_xpm(game, ++i, game->config.we_texture) != 0)
		return (1);
	if (load_xpm(game, ++i, game->config.ea_texture) != 0)
		return (1);
	return (0);
}
