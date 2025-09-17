/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:42:47 by nakoriko          #+#    #+#             */
/*   Updated: 2024/01/21 14:42:49 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd <= -1)
		return ;
	else if (n == -2147483648)
	{
		ft_putstr_fd ("-2147483648", fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd ('-', fd);
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd (n / 10, fd);
		ft_putchar_fd (n % 10 + 48, fd);
	}
	if (n < 10 && n >= 0)
		ft_putchar_fd(n + 48, fd);
}

/*int main ()
{
	ft_putnbr_fd(42, 1);
	return (0);
}*/
