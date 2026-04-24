/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 23:10:15 by sqian             #+#    #+#             */
/*   Updated: 2025/10/25 23:10:26 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	i;

	srclen = 0;
	while (src[srclen])
		srclen++;
	if (size == 0)
		return (srclen);
	i = 0;
	while (src[i] && i < size -1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

/* dst[100]; src[7] = "123456"; strlcpy(dst,src, 4) -> "123\0"
 function does two things: cpy safely ; return the length of source
 
line 27:You only care whether src[i] still has something valid to copy, 
and whether you have enough room in dst. dst[i] is uninitialized
before you write to it. Checking it would be meaningless and could 
even read garbage.

*/
// int	main(void)
// {
// 	char	dst[10];

// 	printf("the string length of src is: %zu\nthe dst is: %s\n",
// 		ft_strlcpy(dst, "Helloshit", sizeof(dst)), dst);
// }
