/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:44:41 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/23 17:00:54 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		len = len + 6;
		return (len);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		len++;
		i++;
	}
	return (len);
}
