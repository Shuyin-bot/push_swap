/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 03:38:50 by sqian             #+#    #+#             */
/*   Updated: 2025/11/20 05:54:12 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	wordcount(const char *s, char c)
{
	int	wcount;

	wcount = 0;
	while (*s)
	{
		while (*s && c == *s)
			s++;
		if (*s)
			wcount++;
		while (*s && c != *s)
			s++;
	}
	return (wcount);
}

void	ft_free(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return ;
}

static char	**ft_fill_words(char **split, char const *s, char c)
{
	int	start;
	int	end;
	int	i;

	start = 0;
	end = 0;
	i = 0;
	while (s[end])
	{
		while (s[end] && s[end] == c)
			end++;
		start = end;
		while (s[end] && s[end] != c)
			end++;
		if (end > start)
		{
			split[i] = ft_substr(s, start, end - start);
			if (!split[i])
				return (ft_free(split), NULL);
			i++;
		}
	}
	split[i] = NULL;
	return (split);
}
/*Line63: 如果第 3 个 substr malloc 失败了,
把 split 里已经创建的单词(前 2 个 substr)全部 free 掉
Line66: if return (ft_free(split));,
then line33: static char**,Line:43: return (NULL);
*/

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc((wordcount(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (ft_fill_words(result, s, c));
}
// ft_split() 负责 一次 malloc（分配指针数组）
// ft_fill_words() 负责 很多次 malloc（每个子字符串）

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;
// 	char	*s3;
// 	char	c;
// 	char	**r;

// 	s1 = "-i-am-pineapple-pie";
// 	s2 = "--pie-pineapple-apple-pie";
// 	s3 = "";
// 	c = '-';
// 	r = ft_split(s1, c);
// 	print_split(r);
// 	ft_free(r);
// 	puts(""); // == printf("\n"); ==> #include <stdio.h>
// 	r = ft_split(s2, c);
// 	print_split(r);
// 	ft_free(r);
// 	r = ft_split(s3, c);
// 	print_split(r);
// 	ft_free(r);
// 	return (0);
// }
