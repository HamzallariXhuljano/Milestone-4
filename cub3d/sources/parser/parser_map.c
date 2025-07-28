/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:38:45 by nakoriko          #+#    #+#             */
/*   Updated: 2025/05/21 15:58:22 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_map(char **mtx, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(mtx[i]);
		i++;
	}
}

int	ft_check_max_lenght(int size, char **mtx)
{
	int	j;
	int	i;
	int	len;

	j = 0;
	i = 0;
	while (j < size)
	{
		len = ft_strlen(mtx[j]);
		if (len > i)
			i = len;
		j++;
	}
	return (i);
}

int	ft_check_map_line(char *str)
{
	int	i;
	int	len;

	len = (int)ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
	i = 0;
	while (str[i])
	{
		if (str[i] == '1' || str[i] == '0' || str[i] == 'N'
			|| str[i] == 'S' || str[i] == 'E' || str[i] == 'W'
			|| str[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_parsing_map(t_game *game, int fd, char **line)
{
	char	**map_mtx;
	int		j;

	j = 0;
	if (ft_check_map_line(*line) != 0)
		return (ft_error("Wrong map matrix"));
	map_mtx = ft_calloc(sizeof(char *), 1000);
	if (!map_mtx)
		return (ft_error("Calloc for map_mtx failed"));
	map_mtx[j] = *line;
	j++;
	*line = get_next_line(fd);
	while ((*line) && ft_check_map_line(*line) == 0)
	{
		map_mtx[j] = *line;
		j++;
		*line = get_next_line(fd);
	}
	map_mtx[j] = NULL;
	game->map.map_mtx = map_mtx;
	game->map.height = j;
	game->map.width = ft_check_max_lenght(j, map_mtx);
	game->map.player_dup = 0;
	return (map_validation(game));
}
