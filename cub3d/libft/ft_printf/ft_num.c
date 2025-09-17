/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:44:27 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/23 17:00:54 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int len)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		len = len + 11;
	}
	else if (n < 0)
	{
		len = len + ft_putchar('-');
		n = n * -1;
	}
	if (n >= 10)
	{
		len = ft_putnbr(n / 10, len);
		len = len + ft_putchar(n % 10 + 48);
	}
	if (n >= 0 && n < 10)
	{
		ft_putchar(n + 48);
		len++;
	}
	return (len);
}

int	ft_unsigned(unsigned int n, int len)
{
	if (n >= 10)
	{
		len = ft_unsigned(n / 10, len);
		len = len + ft_putchar (n % 10 + 48);
	}
	if (n < 10)
	{
		ft_putchar (n + 48);
		len++;
	}
	return (len);
}
