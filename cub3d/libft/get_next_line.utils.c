/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:40:49 by nakoriko          #+#    #+#             */
/*   Updated: 2025/07/17 15:00:59 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *stack, char *buffer)
{
	size_t		i;
	size_t		j;
	char		*p;
	int			slen;

	slen = ft_strlen(stack);
	p = (char *)malloc(sizeof(char) * (slen + ft_strlen(buffer) + 1));
	if (p == 0)
	{
		free(p);
		free(stack);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (stack && stack[i])
	{
		p[i] = stack[i];
		i++;
	}
	while (buffer && buffer[j])
		p[i++] = buffer[j++];
	p[i] = '\0';
	free(stack);
	return (p);
}

void	ft_free_and_null(char *stack)
{
	free(stack);
	stack = NULL;
}
