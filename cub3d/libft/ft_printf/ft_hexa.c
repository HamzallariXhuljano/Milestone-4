/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:46:35 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/23 17:00:54 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned int n, int len)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n >= 16)
	{
		len = ft_hexa((n / 16), len);
		len = len + ft_putchar(hexa[n % 16]);
	}
	else
		len = len + ft_putchar(hexa[n]);
	return (len);
}

int	ft_hexa_up(unsigned int n, int len)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	if (n >= 16)
	{
		len = ft_hexa_up((n / 16), len);
		len = len + ft_putchar(hexa[n % 16]);
	}
	else
		len = len + ft_putchar(hexa[n]);
	return (len);
}

static int	ft_put_address(unsigned long address, int len)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (address >= 16)
	{
		len = ft_put_address((address / 16), len);
		len = len + ft_putchar(hexa[address % 16]);
	}
	else
		len = len + ft_putchar(hexa[address]);
	return (len);
}

int	ft_putptr(void *ptr, int len)
{
	unsigned long	address;

	address = (unsigned long)ptr;
	if (ptr == NULL)
	{
		ft_putstr("(nil)");
		len = len + 5;
	}
	else
	{
		write(1, "0x", 2);
		len = len + 2 + ft_put_address(address, len);
	}
	return (len);
}
