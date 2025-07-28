/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:34:50 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/23 17:28:19 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putptr(void *ptr, int len);
int	ft_hexa(unsigned int n, int len);
int	ft_hexa_up(unsigned int n, int len);
int	ft_putnbr(int n, int len);
int	ft_unsigned(unsigned int n, int len);

#endif
