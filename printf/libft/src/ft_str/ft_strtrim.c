/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 03:34:51 by sqian             #+#    #+#             */
/*   Updated: 2025/11/08 05:39:35 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*rv;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = 0;
	len = ft_strlen(s1);
	while (len > 0 && ft_strchr(set, s1[len - 1]))
		len--;
	rv = (char *)malloc(len + 1);
	if (!rv)
		return (NULL);
	ft_strlcpy(rv, s1, len + 1);
	return (rv);
}

// int main()
// {
// 	char const *s1 = "123abcd123";
// 	char const *set = "0123";

// 	printf("this is the trimmed string %s\n", ft_strtrim(s1, set));
// }

// old version
// char *ft_clean_front(char *rv, const char *set)
// {
// 	int i;
// 	i = 0;
// 	while (rv[0] && set[i])
// 	{
// 		i++;
// 		if (*rv == set[i - 1])
// 		{
// 			i = 0;
// 			rv++;
// 		}
// 	}
// 	return (rv);
// }

// char *ft_strtrim(char const *s1, char const *set)
// {
// 	int i;
// 	char *rv;
// 	int j;

// 	rv = ft_strdup(s1);
// 	rv = ft_clean_front(rv, set);
// 	i = 0;
// 	j = (int)(ft_strlen(rv) - 1);
// 	while (rv[j] && set[i])
// 	{
// 		i++;
// 		if (rv[j] == set[i - 1])
// 		{
// 			rv[j] = '\0';
// 			j--;
// 			i = 0;
// 		}
// 	}
// 	return (rv);
// }

// if the s1 string start with any of the charecters in set;
// const char *set = 'c';
// if first char of s1 is any of set then move pointer one step.

// we need a copy of the string
// how muhc mememory?  --> size o f rv
// malloc (size) of rv + 1)
// cpy: string to string

// we have cleaned the biggning
// we check the length - 1
// reset the while loop in the last

// char *s  "hello";

// s[0] = h;
// s[2] = l;

// s[i] = *(s + i) // if i = 0 ==> *s = s[0]

// s + i = &s[5]

// *s = s[0]
