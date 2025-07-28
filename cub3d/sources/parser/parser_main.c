/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:34:22 by nakoriko          #+#    #+#             */
/*   Updated: 2025/07/17 13:48:01 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <fcntl.h>
#include <unistd.h>

int	texture_is_valid(char *path)
{
	int	len;
	int	fd;

	if (!path)
		return (1);
	len = (int)ft_strlen(path);
	if (len < 4 || ft_strncmp(&path[len - 4], ".xpm", 4) != 0)
		return (1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}

int	check_config(t_config *config)
{
	if (!config->no_texture || !config->so_texture
		|| !config->we_texture || !config->ea_texture)
		return (ft_error("Missing texture"));
	if (texture_is_valid(config->no_texture) != 0)
		return (ft_error("NO texture is invalid"));
	if (texture_is_valid(config->so_texture) != 0)
		return (ft_error("SO texture is invalid"));
	if (texture_is_valid(config->we_texture) != 0)
		return (ft_error("WE texture is invalid"));
	if (texture_is_valid(config->ea_texture) != 0)
		return (ft_error("EA texture is invalid"));
	if (config->floor_dup == 0)
		return (ft_error("FLoor color is missed"));
	if (config->ceiling_dup == 0)
		return (ft_error("Ceiling color is missing"));
	if (config->ceiling_color == config->floor_color)
		return (ft_error ("Different colors needed"));
	return (0);
}

int	ft_scroll_line(char **line, int fd, t_game *game, int res)
{
	*line = get_next_line(fd);
	while (*line)
	{
		if (ft_isempty_line(*line) == 0)
		{
			ft_free_null(*line);
			*line = get_next_line(fd);
			continue ;
		}
		if (ft_istexture_line(*line) != 0)
		{
			res = ft_parsing_texture_line(&game->config, *line);
			ft_free_null(*line);
			if (res != 0)
				return (close(fd), 1);
		}
		else
		{
			if (ft_parsing_map(game, fd, line) != 0)
				return (ft_free_close(*line, fd), 1);
			break ;
		}
		*line = get_next_line(fd);
	}
	return (0);
}

int	ft_check_file(t_game *game, char **line, int fd)
{
	if (check_config(&game->config))
		return (ft_free_close(*line, fd), 1);
	if (!game->map.map_mtx)
	{
		ft_free_close(*line, fd);
		return (ft_error("Map is missing"));
	}
	while (*line)
	{
		if (ft_isempty_line(*line) != 0)
		{
			ft_free_close(*line, fd);
			*line = NULL;
			return (ft_error("Content after map"));
		}
		ft_free_null(*line);
		*line = get_next_line(fd);
	}
	if (*line)
		ft_free_null(*line);
	return (0);
}

int	ft_file_parser(t_game *game, const char *file)
{
	int		fd;
	int		i;
	char	*line;
	int		res;

	res = 0;
	line = NULL;
	i = (int)ft_strlen(file) - 4;
	if (i <= 0 || ft_strncmp(file + i, ".cub", 4) != 0)
		return (ft_error(".cub file is needed"));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_error("Wrong config file"));
	if (ft_scroll_line(&line, fd, game, res) != 0)
		return (1);
	if (ft_check_file(game, &line, fd) != 0)
		return (1);
	close(fd);
	return (0);
}
// int	ft_file_parser(t_game *game, const char *file)
// {
// 	int		fd;
// 	int		i;
// 	char	*line;
// 	int		res;

// 	line = NULL;
// 	i = (int)ft_strlen(file) - 4;
// 	if (i <= 0 || ft_strncmp(file + i, ".cub", 4) != 0)
// 		return (ft_error(".cub file is needed"));
// 	fd = open(file, O_RDONLY);
// 	// forse eliminare, forse get next line faceva controllo di genre:
// 	if (fd < 0)
// 		return (ft_error("Wrong config file"));
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		if (ft_isempty_line(line) == 0) //строка пустая
// 		{
// 			free(line);
// 			line = NULL;
// 			line = get_next_line(fd);
// 			continue ;
// 		}
// 		if (ft_istexture_line(line) != 0)
// 		{
// 			res = ft_parsing_texture_line(&game->config, line);
// 			free(line);
// 			line = NULL;
// 			if (res != 0)
// 			{
// 				close(fd);
// 				return (1);
// 			}
// 		}
// 		else
// 		{
// 			if (ft_parsing_map(game, fd, &line) != 0)
// 			{
// 				free(line);
// 				close(fd);
// 				return (1);
// 			}
// 			//free(line);
// 			break ;
// 		}
// 		line = get_next_line(fd);
// 	}
// 	if (check_config(&game->config))
// 	{
// 		free(line);
// 		close(fd);
// 		return (1);
// 	}
// 	if (!game->map.map_mtx)
// 	{
// 		free(line);
// 		close(fd);
// 		return (ft_error("Map is missing"));
// 	}
// 	while (line)
// 	{
// 		if (ft_isempty_line(line) != 0) // строка не пустая
// 		{
// 			free(line);
// 			line = NULL;
// 			close(fd);
// 			return (ft_error("Content after map"));
// 		}
// 		free(line);
// 		line = NULL;
// 		line = get_next_line(fd);
// 	}
// 	if (line)
// 	{
// 		free(line);
// 		line = NULL;
// 	}
// 	close(fd);
// 	return (0);
// }
