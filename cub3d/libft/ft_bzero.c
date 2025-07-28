/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:39:36 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/23 16:57:47 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

/*int main()
{
	char s[] = "ciao";
	ft_bzero(s, 4);
	ft_printf("%p\n", ft_bzero(s, 4));
	ft_printf("%s\n", s);
	return (0);
}*/
