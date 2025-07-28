/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:40:18 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/23 17:00:54 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(char format, va_list arg, int *i)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = len + ft_putchar(va_arg(arg, int));
	else if (format == 's')
		len = len + ft_putstr(va_arg(arg, char *));
	else if (format == 'd')
		len = len + ft_putnbr(va_arg(arg, int), len);
	else if (format == 'i')
		len = len + ft_putnbr(va_arg(arg, int), len);
	else if (format == 'u')
		len = len + ft_unsigned(va_arg(arg, unsigned int), len);
	else if (format == '%')
		len = len + ft_putchar('%');
	else if (format == 'x')
		len = len + ft_hexa(va_arg(arg, unsigned int), len);
	else if (format == 'X')
		len = len + ft_hexa_up(va_arg(arg, unsigned int), len);
	else if (format == 'p')
		len = len + ft_putptr(va_arg(arg, void *), len);
	else
		i--;
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '\0')
			return (-1);
		else if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			len = len + ft_check(str[i], arg, &i);
		}
		else
			len = len + ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (len);
}

/*int main ()
{
	int i;
	int f;
	
	f = ft_printf("*");
	ft_printf("%d\n", f);
	i = ft_printf("*");
	ft_printf("%d\n", i);
	
	f = ft_printf("%c", '0');
	ft_printf("%d\n", f);
	i = ft_printf("%c", '0');
	ft_printf("%d\n", i);
	
	f = ft_printf("%s", NULL);
	ft_printf("%d\n", f);
	i = ft_printf("%s", NULL);
	ft_printf("%d\n", i);
	
	f = ft_printf("%s", "");
	ft_printf("%d\n", f);
	i = ft_printf("%s", "");
	ft_printf("%d\n", i);
	
	f = ft_printf("%p", NULL);
	ft_printf("%d\n", f);
	i = ft_printf("%p", NULL);
	ft_printf("%d\n", i);
	
	f = ft_printf("%%");
	ft_printf("%d\n", f);
	i = ft_printf("%%");
	ft_printf("%d\n", i);
	
	f = ft_printf("%%%");
	ft_printf("%d\n", f);
	i = ft_printf("%%%");
	ft_printf("%d\n", i);
	
	return (0);
}*/
