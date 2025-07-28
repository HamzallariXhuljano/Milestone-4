/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:41:01 by nakoriko          #+#    #+#             */
/*   Updated: 2024/09/02 21:02:49 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0' && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
/*int main()
{
	char s[] = "teste";
	ft_printf("%p\n", s);
	ft_printf("%p\n", ft_strchr("teste", 'e'+ 256 ));
	ft_printf("%p\n", strchr("teste", 'e' + 256));
	return (0);	
}*/
