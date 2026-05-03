/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 03:59:52 by sqian             #+#    #+#             */
/*   Updated: 2025/11/20 05:50:09 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Iterates through the list ’lst’ and applies the
//function ’f’ to the content of each node.
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
//f(lst->content) 对当前节点的内容执行函数 f
//lst = lst->next; 走到下一个节点。lst++
