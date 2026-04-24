/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 05:28:12 by sqian             #+#    #+#             */
/*   Updated: 2025/11/09 23:18:05 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ncounter(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*s;
	long	nb;

	nb = (long)n;
	count = ft_ncounter(nb);
	s = (char *)malloc(count + 1);
	if (!s)
		return (NULL);
	s[count] = '\0';
	if (nb == 0)
		s[0] = '0';
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		s[--count] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (s);
}

/*
convert int to long to avoid INT_MIN (-2147483648) negative overflow
 ==> 2147483648 (INT_MAX =  2147483647)
*/
