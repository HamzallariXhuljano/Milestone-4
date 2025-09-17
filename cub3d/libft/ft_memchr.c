/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:41:30 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/23 17:05:15 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*p;
	int		i;

	p = (char *)s;
	i = 0;
	while (n > 0)
	{
		if (p[i] == (char) c)
			return (&p[i]);
		i++;
		n--;
	}
	return (NULL);
}

/*int main ()
{
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	ft_printf("%p\n", ft_memchr(s, 2 + 256, 3));
	ft_printf("%p\n", memchr(s, 2 + 256, 3));
	return (0);
}*/
