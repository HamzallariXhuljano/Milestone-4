/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:26:19 by nakoriko          #+#    #+#             */
/*   Updated: 2025/07/05 13:26:19 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	player_pos_check(t_map *map, int i, int j)
{
	char	c;

	while (j < map->height)
	{
		while (map->map_mtx[j][i])
		{
			c = map->map_mtx[j][i];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				map->player_dup = map->player_dup + 1;
				if (map->player_dup > 1)
					return (ft_error("Player's duplicate!"));
				map->player_x = i;
				map->player_y = j;
				map->player_dir = c;
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	empty_line_inside(char **mtx, int height)
{
	int	j;

	j = 0;
	while (j < height)
	{
		if (ft_strlen(mtx[j]) == 0)
			return (1);
		j++;
	}
	return (0);
}

int	ft_check_chars_inside(t_map *map, int i, int len, int j)
{
	while (j < map->height)
	{
		len = (int)ft_strlen(map->map_mtx[j]);
		if (len > 0 && map->map_mtx[j][len - 1] == '\n')
			map->map_mtx[j][len - 1] = '\0';
		i = 0;
		while (i < len)
		{
			if (map->map_mtx[j][i] == '1' || map->map_mtx[j][i] == '0' ||
				map->map_mtx[j][i] == 'N' || map->map_mtx[j][i] == 'S' ||
				map->map_mtx[j][i] == 'E' || map->map_mtx[j][i] == 'W' ||
				map->map_mtx[j][i] == ' ')
				i++;
			else
				return (1);
		}
		j++;
	}
	return (0);
}

int	map_validation(t_game *game)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	if (ft_check_chars_inside(&game->map, i, len, j) != 0)
		return (ft_error("Wrong map matrix"));
	if (player_pos_check(&game->map, i, j) != 0)
		return (1);
	if (game->map.player_dup == 0)
		return (ft_error("No player on the map!"));
	if (map_is_closed (game->map) != 0)
		return (1);
	return (0);
}
