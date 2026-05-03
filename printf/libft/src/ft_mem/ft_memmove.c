/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:47:17 by sqian             #+#    #+#             */
/*   Updated: 2025/11/13 20:38:24 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*destptr;
	const unsigned char	*srcptr;

	destptr = (unsigned char *) dest;
	srcptr = (const unsigned char *) src;
	if (destptr == NULL && srcptr == NULL)
		return (NULL);
	i = 0;
	if (destptr > srcptr)
	{
		while (n-- > 0)
		{
			destptr[n] = srcptr[n];
		}
	}
	else
	{
		while (i < n)
		{
			destptr[i] = srcptr[i];
			i++;
		}
	}
	return (dest);
}
/*
memmove 是操作内存字节的函数，不是操作整数、浮点数或结构体的。
在 C 语言标准里，唯一明确能安全访问任意内存字节的类型就是 unsigned char。


因此要把 void * 转成 unsigned char *，原因是：

1.方便做加减、索引操作：destptr[i] = srcptr[i];
2.避免符号扩展（signed char 可能会把最高位当符号位处理）。
3.标准规定，用 unsigned char * 访问任何对象的底层内存都是合法的。
*/
