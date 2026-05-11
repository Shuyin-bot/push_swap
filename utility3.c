/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qianshuyin <qianshuyin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:32:35 by qianshuyin        #+#    #+#             */
/*   Updated: 2026/05/10 14:44:51 by qianshuyin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	free_stack(t_stack *s)
{
	t_node	*node;
	t_node	*previous;

	if (!s)
		return ;
	if (!s->top)
	{
		free(s);
		return ;
	}
	node = s->top;
	while (node->next)
	{
		previous = node;
		node = node->next;
		free(previous);
	}
	free(node);
	free(s);
}
