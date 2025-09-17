/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:05:18 by nakoriko          #+#    #+#             */
/*   Updated: 2025/07/17 13:54:54 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_error("Wrong number of arguments"));
	ft_bzero(&game, sizeof(t_game));
	if (ft_file_parser(&game, argv[1]) != 0)
	{
		free_all(&game);
		get_next_line(-1);
		return (1);
	}
	if (ft_init(&game) != 0)
		return (1);
	if (init_player(&game) != 0)
		return (1);
	ft_rerender(&game);
	mlx_hook(game.win, 17, 0, handle_exit, &game);
	mlx_hook(game.win, 2, 1L << 0, handle_key, &game);
	mlx_loop(game.mlx);
	ft_pre_exit(&game);
	return (0);
}
