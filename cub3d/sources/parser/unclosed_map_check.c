/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unclosed_map_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:38:45 by nakoriko          #+#    #+#             */
/*   Updated: 2025/07/16 15:44:44 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_safe_zone(char **mtx, int y, int x, int height)
{
	if (y < 0 || y >= height || x < 0)
		return (1);
	if (mtx[y] == NULL)
		return (1);
	if (x >= (int)ft_strlen(mtx[y]))
		return (1);
	if ((mtx[y][x]) && (mtx[y][x] == ' ' || mtx[y][x] == '\0'
		|| ft_strlen(mtx[y]) == 0))
		return (1);
	return (0);
}

int	ft_check_around(char **mtx, int y, int x, int height)
{
	char	c;

	c = mtx[y][x];
	if (c != '0' && c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return (0);
	if (ft_safe_zone(mtx, y - 1, x, height))
		return (1);
	if (ft_safe_zone(mtx, y + 1, x, height))
		return (1);
	if (ft_safe_zone(mtx, y - 1, x + 1, height))
		return (1);
	if (ft_safe_zone(mtx, y, x - 1, height))
		return (1);
	if (ft_safe_zone(mtx, y, x + 1, height))
		return (1);
	return (0);
}

int	map_is_closed(t_map map)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (j < map.height)
	{
		while (map.map_mtx[j][i])
		{
			if (ft_check_around(map.map_mtx, j, i, map.height) != 0)
				return (ft_error("Unclosed map!"));
			i++;
		}
		j++;
		i = 0;
	}
	return (0);
}
