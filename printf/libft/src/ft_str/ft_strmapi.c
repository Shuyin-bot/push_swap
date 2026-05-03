/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 06:29:19 by sqian             #+#    #+#             */
/*   Updated: 2025/11/09 23:18:33 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

// char	coolf(unsigned int i, char c)
// {
// 	(void)i;
// 	return (c + 1);
// }

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newstr;
	size_t	len;
	int		i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	newstr = ft_calloc((len + 1), sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	return (newstr);
}

// int main()
// {
// 	char const	*s = "pineapple pen";
// 	char		*f;
// 	f = ft_strmapi(s, &coolf);
// 	printf("original: %s\n", s);
// 	printf("manipulated: %s\n", f);
// 	free(f);
// 	return (0);
// }
