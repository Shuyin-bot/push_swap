/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 03:46:21 by sqian             #+#    #+#             */
/*   Updated: 2025/11/20 05:48:51 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Takes a node as parameter and frees its content
using the function ’del’. Free the node itself but
does NOT free the next node.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst && del)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			*lst = temp;
		}
		*lst = NULL;
	}
}

/*while there is a node
temp will have the next of the current node;
function del will have the content of current node;
kill current node;
lst will have the temp variable

at the end set to null;

Line28://先记住下一个节点
// free 内容
// free 当前节点
// 让链表头指向下一个节点
// 最后把链表头设成 NULL
*/
