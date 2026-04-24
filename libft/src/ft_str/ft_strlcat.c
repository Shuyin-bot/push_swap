/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 02:29:00 by sqian             #+#    #+#             */
/*   Updated: 2025/10/26 16:01:22 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	srclen;
	size_t	destlen;
	size_t	i;

	srclen = ft_strlen(src);
	destlen = 0;
	while (dest[destlen] && destlen < size)
		destlen++;
	if (destlen == size)
	{
		return (destlen + srclen);
	}
	i = 0;
	while (src[i] && (destlen + i + 1) < size)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = 0;
	return (destlen + srclen);
}

// int	main(void)
// {
// 	char dest[10] = "12";
// 	printf("%zu", ft_strlcat(dest, "shit", 5));
// }
/*
in both strlcpy and strlcat, the size argument means
“the total capacity of the destination buffer (dst)"

return the total length of the string it tried to create

cc -lbsd to use the strlcat function
*/