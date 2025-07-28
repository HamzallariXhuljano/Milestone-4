/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:40:00 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/23 17:06:30 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (!dest && !src)
		return (NULL);
	if (d <= s)
		ft_memcpy(d, s, n);
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (d);
}
/*int main ()
{
	char dst[] = "ciao";
	char src[] = "1234";
	ft_printf("%p\n", ft_memmove(dst, src, 3));
	ft_printf("%p\n", memmove(dst, src, 3));
}*/
