/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:58:04 by sqian             #+#    #+#             */
/*   Updated: 2025/11/05 01:01:47 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*b;

	b = malloc(ft_strlen(s) + 1);
	if (!b)
		return (NULL);
	ft_strlcpy(b, s, ft_strlen(s) + 1);
	return (b);
}
