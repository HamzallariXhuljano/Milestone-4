/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:40:12 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/23 17:04:27 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libft.h"

size_t	ft_strlen_2(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while ((i < size - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*int main ()
{
	char dst[100];
	char src[] = "aasdjj;s;sa";

	
	//ft_printf("%ld\n", ft_strlcpy(dst, src, 100));
	//ft_strlcpy(dst, src, 100);
	//ft_printf("%s\n", dst);
	//ft_printf("%ld\n", strlcpy(dst, src, 2));
	//ft_printf("%d\n", strlcpy(dst, src, 3));
	return (0);
}*/
