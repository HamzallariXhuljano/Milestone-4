/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:53:02 by nakoriko          #+#    #+#             */
/*   Updated: 2025/07/17 14:59:01 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *line, const char *stack)
{
	int	i;

	i = 0;
	while (stack[i] != '\n' && stack[i])
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

void	ft_free(char **buffer, char **stack)
{
	free(*buffer);
	free(*stack);
	*stack = NULL;
}

char	*ft_temp(char *stack, char *buffer, char *line)
{
	char	*temp;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (stack[i] != '\n' && stack[i])
		i++;
	temp = malloc(sizeof(char) * (((ft_strlen(stack)) - i + 1)));
	if (temp == NULL)
	{
		ft_free(&buffer, &stack);
		free(line);
		return (NULL);
	}
	i++;
	while (stack[i])
		temp[j++] = stack[i++];
	temp[j] = '\0';
	free(stack);
	free (buffer);
	return (temp);
}

char	*ft_newline(char *stack, char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (stack[i] != '\n' && stack[i])
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
	{
		ft_free(&buffer, &stack);
		return (NULL);
	}
	line = ft_strcpy(line, stack);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stack = NULL;
	char		*buffer;
	char		*line;
	int			read_bytes;

	if (fd == -1)
		return (ft_free_and_null(stack), NULL);
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (buffer == NULL || BUFFER_SIZE < 1 || fd < 0)
		return (free(buffer), NULL);
	read_bytes = 1;
	while ((read_bytes > 0) && (ft_strchr(stack, '\n') == NULL))
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		stack = ft_strjoin_gnl(stack, buffer);
	}
	if (ft_strlen(stack) == 0)
		return (ft_free(&buffer, &stack), NULL);
	line = ft_newline(stack, buffer);
	if ((ft_strlen(stack)) - (ft_strlen(line)) == 0)
		return (ft_free(&buffer, &stack), line);
	stack = ft_temp(stack, buffer, line);
	return (line);
}
