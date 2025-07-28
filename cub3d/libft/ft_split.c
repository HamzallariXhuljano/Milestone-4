/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:44:06 by nakoriko          #+#    #+#             */
/*   Updated: 2024/01/21 14:44:07 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			j++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (j);
}

static size_t	ft_len(char const *s, char c)
{
	size_t	l;

	l = 0;
	while (s[l] != c && s[l] != '\0')
		l++;
	return (l);
}

void	ft_free_mtx(char **mtx, size_t k)
{
	while (k)
	{
		free(mtx[k]);
		k--;
	}
	free(mtx[k]);
	free(mtx);
}

char	**split_1(char const *s, char c, char **mtx)
{
	size_t	j;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (k < (ft_count(s, c)))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = 0;
		mtx[k] = (char *)malloc(sizeof(char) * (ft_len((s + i), c) + 1));
		if (mtx[k] == NULL)
		{
			ft_free_mtx(mtx, k);
			return (NULL);
		}
		while ((s[i] != '\0') && (s[i] != c))
			mtx[k][j++] = s[i++];
		mtx[k][j] = '\0';
		k++;
	}
	mtx[k] = NULL;
	return (mtx);
}

char	**ft_split(char const *s, char c)
{
	char	**mtx;
	size_t	words;

	words = ft_count(s, c);
	mtx = (char **)malloc(sizeof(char *) * (words + 1));
	if (mtx == NULL)
		return (NULL);
	mtx = split_1(s, c, mtx);
	return (mtx);
}

/*int main()
{
	ft_printf("%zu", ft_len("ggggg", 'g'));
	return (0);
}*/
/*int main()
{
	char	**array;
	int i;
	i = 0;
	array = ft_split ("\t\t\t\thello!\t\t\t\t", '\t');
	while ( array[i])
	{
		ft_printf("%s\n", array[i]);
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}*/
