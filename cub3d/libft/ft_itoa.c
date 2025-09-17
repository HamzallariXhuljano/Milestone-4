/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:09:31 by nakoriko          #+#    #+#             */
/*   Updated: 2024/01/21 12:09:49 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h" 

int	ft_int_len(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_make(char *str, int i, int n)
{
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	str[i] = '\0';
	i--;
	while (n != 0)
	{
		str[i] = n % 10 + 48;
		n = n / 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	if (n == -2147483647 - 1)
	{
		str = malloc(sizeof(char) * 12);
		if (str == 0)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	else
	{
		i = ft_int_len(n);
		str = malloc(sizeof(char) * (i + 1));
		if (str == 0)
			return (0);
		if (n == 0)
			str[0] = '0';
		ft_make(str, i, n);
	}
	return (str);
}

/*int main ()
{
	int n = -2147483648;
	ft_printf("%s\n", ft_itoa(n));
	//ft_printf("%s\n", itoa(n));
	return (0);
}*/
