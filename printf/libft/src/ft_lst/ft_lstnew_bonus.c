/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 01:39:44 by sqian             #+#    #+#             */
/*   Updated: 2025/11/12 02:52:55 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *mycontent)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = mycontent;
	new->next = NULL;
	return (new);
}

// int main()
// {
//	char *meow = "Hallo";

//	t_list *node = ft_lstnew(meow);

//	// %s for a string (because content is a char*)
//	printf("Node content: %s\n", (char *)node->content);

//	free(node);
//	return (0);
// }
