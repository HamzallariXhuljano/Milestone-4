/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:40:21 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/23 17:07:03 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlen_2(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	j = ft_strlen(dst);
	i = 0;
	while (j < size - 1 && src[i] != '\0')
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
/*int main ()
{
	char dst[] = "pqrstuvwxyz";
	char src[] = "abcd";
	ft_printf("%ld\n", ft_strlcat(dst, src, 1));
	
	//ft_strlcat(dst, src, 0);
	//ft_printf("%s\n", dst);
	//ft_printf("%d\n", strlcpy(dst, src, 3));
	
}*/
