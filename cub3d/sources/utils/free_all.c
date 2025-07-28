/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:27:04 by nakoriko          #+#    #+#             */
/*   Updated: 2025/07/17 13:50:34 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_t_config(t_config *cf)
{
	if (cf->no_texture)
	{
		free(cf->no_texture);
		cf->no_texture = NULL;
	}
	if (cf->so_texture)
	{
		free(cf->so_texture);
		cf->so_texture = NULL;
	}
	if (cf->we_texture)
	{
		free(cf->we_texture);
		cf->we_texture = NULL;
	}
	if (cf->ea_texture)
	{
		free(cf->ea_texture);
		cf->ea_texture = NULL;
	}
	cf->ceiling_color = 0;
	cf->floor_color = 0;
}

void	free_t_map(char **mtx, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(mtx[i]);
		i++;
	}
	free(mtx);
}

void	free_all(t_game *game)
{
	free_t_config(&game->config);
	free_t_map(game->map.map_mtx, game->map.height);
}

void	ft_pre_exit(t_game *game)
{
	int	i;

	i = 0;
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	if (game->img.ptr)
		mlx_destroy_image(game->mlx, game->img.ptr);
	while (i < 4)
	{
		if (game->wall[i].ptr)
			mlx_destroy_image(game->mlx, game->wall[i].ptr);
		i++;
	}
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free_all(game);
	if (game->mlx)
		free(game->mlx);
}
