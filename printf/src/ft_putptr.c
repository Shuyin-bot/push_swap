/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 06:55:36 by sqian             #+#    #+#             */
/*   Updated: 2025/12/04 01:11:07 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdint.h>

static int	ft_puthex_ptr(uintptr_t n)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex_ptr(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int			count;
	uintptr_t	addr;

	if (!ptr)
		return (ft_putstr("(nil)"));
	addr = (uintptr_t)ptr;
	count = 0;
	count += ft_putstr("0x");
	count += ft_puthex_ptr(addr);
	return (count);
}
