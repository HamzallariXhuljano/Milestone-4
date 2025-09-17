/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:29:30 by nakoriko          #+#    #+#             */
/*   Updated: 2025/07/17 13:54:11 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	trim_line(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
}

int	check_rest_of_the_line(char *line, int i)
{
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ')
			return (ft_error("Incorrect color line"));
		i++;
	}
	return (0);
}

int	ft_isempty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_free_close(char *line, int fd)
{
	free(line);
	close(fd);
}

void	ft_free_null(char *line)
{
	free(line);
	line = NULL;
}
