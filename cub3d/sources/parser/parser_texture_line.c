/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:17:30 by nakoriko          #+#    #+#             */
/*   Updated: 2025/07/17 13:48:59 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_istexture_line(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0
		|| ft_strncmp(line, "F ", 2) == 0
		|| ft_strncmp(line, "C ", 2) == 0)
		return (1);
	else
		return (0);
}

int	texture_check(char **texture_path, int *dup, char *line, int i)
{
	while (line[i] == ' ') // controllare se bisogna di cambiare per altri tab
		i++;
	if (*dup > 1)
		return (ft_error("Duplicate in config file"));
	if (!line[i])
		return (ft_error("Missing path in config file"));
	*texture_path = ft_strdup(&line[i]);
	trim_line(*texture_path);
	if (*texture_path == NULL)
		return (ft_error("Malloc failed in texture parsing"));
	*dup = 1;
	return (0);
}

int	rgb_parser(char *line, int *i)
{
	int	color_code;

	color_code = 0;
	while (line[*i] == ' ')
		(*i)++;
	if (line[*i] < '0' || line[*i] > '9')
		return (-1);
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		color_code = color_code * 10 + (line[*i] - 48);
		(*i)++;
	}
	if (color_code < 0 || color_code > 255)
		return (-1);
	return (color_code);
}

int	color_check(int *color, int *dup, char *line, int i)
{
	int	r;
	int	g;
	int	b;

	if (*dup > 0)
		return (ft_error("Color duplication!"));
	r = rgb_parser(line, &i);
	if (r < 0)
		return (ft_error("Invalid color value!"));
	if (line[i] != ',')
		return (ft_error("After color needs ','"));
	i++;
	g = rgb_parser(line, &i);
	if (g < 0)
		return (ft_error("Invalid color value!"));
	if (line[i] != ',')
		return (ft_error("After color needs ','"));
	i++;
	b = rgb_parser(line, &i);
	if (b < 0)
		return (ft_error("Invalid color value!"));
	*color = (r << 16) | (g << 8) | b;
	*dup = 1;
	return (check_rest_of_the_line(line, i));
}

int	ft_parsing_texture_line(t_config *config, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (texture_check(&config->no_texture, &config->no_dup, line, 3));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (texture_check(&config->so_texture, &config->so_dup, line, 3));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (texture_check(&config->we_texture, &config->we_dup, line, 3));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (texture_check(&config->ea_texture, &config->ea_dup, line, 3));
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (color_check(&config->floor_color, &config->floor_dup, line, 2));
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (color_check(&config->ceiling_color,
				&config->ceiling_dup, line, 2));
	else
		return (ft_error("Wrong configuration line"));
}
