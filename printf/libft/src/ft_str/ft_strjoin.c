/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 01:44:49 by sqian             #+#    #+#             */
/*   Updated: 2025/11/05 01:02:48 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		l1;
	int		l2;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	s = malloc(l1 + l2 + 1);
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, l1 + 1);
	ft_strlcat(s, s2, l1 + l2 + 1);
	return (s);
}
// 我们需要获取这两个字符串的长度，以便为它们分配足够的内存。
// 然后我们可以分配足够的内存来存储字符串以及空字符终止符。
// 然后我们将 s1 复制到我们新分配的字符串中(strlcpy)，
// 然后复制 s2，最后我们可以将最后一个字符设置为 NUL(strlcat) 。
