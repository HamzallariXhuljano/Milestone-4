/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:34:39 by nakoriko          #+#    #+#             */
/*   Updated: 2024/01/21 13:34:40 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
#include "libft.h"

/*int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}*/

int	ft_search(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	size_t		i;
	char		*p;

	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1 && ft_search(s1[start], (char *)set))
		start++;
	while (end > start && ft_search(s1[end - 1], (char *)set))
		end --;
	p = malloc(sizeof(char) * (end - start) + 1);
	if (p == 0)
		return (NULL);
	while (start < end)
	{
		p[i] = s1[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*int main()
{
	char s1[] = "123ciao123";
	char set[] = "124";
	ft_printf("%p\n", ft_strtrim(s1, set));
	ft_printf("%s\n", ft_strtrim(s1, set));
	return (0);
}*/
