/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 00:49:36 by sqian             #+#    #+#             */
/*   Updated: 2025/11/10 03:18:30 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == 0)
		return ((char *)big);
	i = 0;
	j = 0;
	while (i < len && big[i + j])
	{
		j = 0;
		while (little[j] != '\0' && (i + j < len) && big[i + j] == little[j])
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

// # include <stdio.h>

// int	main(void)
// {
// 	printf("%s", ft_strnstr("press h for help or q to quit", "h", 20));
// }
