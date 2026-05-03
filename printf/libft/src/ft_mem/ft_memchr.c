/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:51:03 by sqian             #+#    #+#             */
/*   Updated: 2025/11/18 04:10:48 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	i = 0;
	str = (const unsigned char *)s;
	while (i < n)
	{
		if ((unsigned char)c == str[i])
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	printf("%p", ft_memchr("wanna quit", 'n', 10));
// }
/*
s casts to const unsigned char
c casts to unsigned char
*/
