/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:34:16 by sqian             #+#    #+#             */
/*   Updated: 2025/11/18 01:50:01 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

// int main(void)
// {
//     char str1[] = "Hello";
//     char str2[] = "Hello";
//     char str3[] = "Hellp";
//     char str4[] = "Hell";

//     printf("测试1: %d\n", ft_memcmp(str1, str2, 5));  // 输出: 0 (相等)
//     printf("测试2: %d\n", ft_memcmp(str1, str3, 5));  // 输出: 负数 (o < p)
//     printf("测试3: %d\n", ft_memcmp(str1, str4, 5));  // 输出: 正数 (o > 空)
//     printf("测试4: %d\n", ft_memcmp(str1, str2, 3));  // 输出: 0 (前3个字符相等)

//     return (0);
// }
