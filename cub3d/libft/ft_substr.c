/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:24:01 by nakoriko          #+#    #+#             */
/*   Updated: 2024/01/21 12:24:07 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h" 
#include <stdio.h>
#include <stdlib.h>

static size_t	ft_len(char const *s, unsigned int start, size_t len)
{
	if (start > ft_strlen(s))
		len = 0;
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*p;
	size_t	a;

	a = ft_len(s, start, len);
	p = malloc(sizeof(char) * a + 1);
	if (p == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			p[j] = s[i];
			j++;
		}
		i++;
	}
	p[j] = '\0';
	return (p);
}

/*int main ()
{
	ft_printf("%s\n", ft_substr("lorem ipsum dolor sit amet", 7, 10));
	//ft_printf("%p\n", substr("", 2, 1));
	//ft_printf("%s\n", ft_substr("abcdef", -1, 1));
	//ft_printf("%s\n", substr(s, -1, 1));
	return (0);
}*/
