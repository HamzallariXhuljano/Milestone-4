/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:00:13 by nakoriko          #+#    #+#             */
/*   Updated: 2025/07/17 15:01:49 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	handle_exit(t_game *game)
{
	ft_pre_exit(game);
	exit (0);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 65307 || keycode == 53)
		handle_exit(game);
	if (keycode == W)
		forward_move(game);
	if (keycode == S)
		backward_move(game);
	if (keycode == A)
		left_move(game);
	if (keycode == D)
		right_move(game);
	if (keycode == LEFT)
		left_rotate(game);
	if (keycode == RIGHT)
		right_rotate(game);
	ft_rerender(game);
	return (0);
}
