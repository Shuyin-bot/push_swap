/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 03:38:51 by sqian             #+#    #+#             */
/*   Updated: 2025/11/13 20:49:34 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Takes a node as parameter and frees its content
using the function ’del’. Free the node itself but
does NOT free the next node.
*/
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
//call the function del and give the content of the list
//kill it
