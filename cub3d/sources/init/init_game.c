/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:38:57 by nakoriko          #+#    #+#             */
/*   Updated: 2025/07/16 15:43:41 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_init(t_game *game)
{
	game->width = SCREEN_WIDTH;
	game->height = SCREEN_HEIGHT;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free_all(game), ft_error("Mlx_init failed"));
	game->win = mlx_new_window(game->mlx, game->width, game->height, "cub3D");
	if (!game->win)
		return (free_all(game), ft_error("MLX_new_window failed"));
	if (ft_init_textures(game) != 0)
		return (ft_pre_exit(game), 1);
	if (init_image(game, game->width, game->height) != 0)
		return (ft_pre_exit(game), 1);
	return (0);
}
