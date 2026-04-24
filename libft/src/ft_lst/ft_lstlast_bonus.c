/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 03:12:24 by sqian             #+#    #+#             */
/*   Updated: 2025/11/13 20:43:30 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//find the last node
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*
	while (still have nodes and nodes hasn't finished)
		lst = the next node;
*/
