/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:18:08 by sqian             #+#    #+#             */
/*   Updated: 2025/10/27 02:25:43 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((char)c == s[i])
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == 0)
		return ((char *)(s + i));
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s = "meow sadface";

// 	printf("%s", &s);
// }

// old code:
// while (s[i] != (char)c && s[i])
// 	i++;
// if (s[i] || (char)c == '\0')
// 	return ((char *)(s + i));
// return (NULL);