/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 04:09:23 by sqian             #+#    #+#             */
/*   Updated: 2025/12/04 01:10:36 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	count;

	if (!s)
		return (write(1, "(null)", 6));
	count = 0;
	while (*s)
	{
		count += ft_putchar(*s);
		s++;
	}
	return (count);
}

int	ft_putnb(int n)
{
	int		count;
	long	num;

	count = 0;
	num = (long)n;
	if (num < 0)
	{
		count += ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
		count += ft_putnb(num / 10);
	ft_putchar((num % 10) + '0');
	return (count + 1);
}
//try count += ft_putchar((num % 10) + '0');
//	return (count);

int	ft_putunb(unsigned int n)
{
	int		count;
	long	num;

	count = 0;
	num = (long)n;
	if (num >= 10)
		count += ft_putunb(num / 10);
	ft_putchar((num % 10) + '0');
	return (count + 1);
}

int	ft_puthex(unsigned int n, char c)
{
	int		count;
	char	*base;

	base = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, c);
	ft_putchar(base[n % 16]);
	return (count + 1);
}
