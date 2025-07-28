/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_asdw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:12:10 by nakoriko          #+#    #+#             */
/*   Updated: 2025/07/16 15:43:35 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	forward_move(t_game *game)
{
	double	new_x;
	double	new_y;
	double	margin;

	margin = 0.4;
	new_x = game->player.pos_x + game->player.dir_x * MOVE_SPEED;
	new_y = game->player.pos_y;
	if (is_position_safe(game, new_x, new_y, margin) == 0)
		game->player.pos_x = new_x;
	new_x = game->player.pos_x;
	new_y = game->player.pos_y + game->player.dir_y * MOVE_SPEED;
	if (is_position_safe(game, new_x, new_y, margin) == 0)
		game->player.pos_y = new_y;
}

void	backward_move(t_game *game)
{
	double	new_x;
	double	new_y;
	double	margin;

	margin = 0.4;
	new_x = game->player.pos_x - game->player.dir_x * MOVE_SPEED;
	new_y = game->player.pos_y;
	if (is_position_safe(game, new_x, new_y, margin) == 0)
		game->player.pos_x = new_x;
	new_x = game->player.pos_x;
	new_y = game->player.pos_y - game->player.dir_y * MOVE_SPEED;
	if (is_position_safe(game, new_x, new_y, margin) == 0)
		game ->player.pos_y = new_y;
}

void	right_move(t_game *game)
{
	double	new_x;
	double	new_y;
	double	margin;

	margin = 0.4;
	new_x = game->player.pos_x - game->player.dir_y * MOVE_SPEED;
	new_y = game->player.pos_y;
	if (is_position_safe(game, new_x, new_y, margin) == 0)
		game->player.pos_x = new_x;
	new_x = game->player.pos_x;
	new_y = game->player.pos_y + game->player.dir_x * MOVE_SPEED;
	if (is_position_safe(game, new_x, new_y, margin) == 0)
		game ->player.pos_y = new_y;
}

void	left_move(t_game *game)
{
	double	new_x;
	double	new_y;
	double	margin;

	margin = 0.4;
	new_x = game->player.pos_x + game->player.dir_y * MOVE_SPEED;
	new_y = game->player.pos_y;
	if (is_position_safe(game, new_x, new_y, margin) == 0)
		game->player.pos_x = new_x;
	new_x = game->player.pos_x;
	new_y = game->player.pos_y - game->player.dir_x * MOVE_SPEED;
	if (is_position_safe(game, new_x, new_y, margin) == 0)
		game ->player.pos_y = new_y;
}

int	is_position_safe(t_game *game, double x, double y, double margin)
{
	int	map_x;
	int	map_y;

	if (x < margin || y < margin || x >= game->map.width - margin
		|| y >= game->map.height - margin)
		return (-1);
	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= game->map.width
		|| map_y < 0 || map_y >= game->map.height)
		return (-1);
	if (game->map.map_mtx[map_y][map_x] == '1')
		return (-1);
	return (0);
}
