/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qianshuyin <qianshuyin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 05:38:22 by qianshuyin        #+#    #+#             */
/*   Updated: 2026/05/03 19:21:14 by qianshuyin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_top(t_stack *stack, t_node *node)
{
	t_node	*old_top;

	old_top = stack->top;
	stack->top = node;
	stack->top->next = old_top;
}

void	push_bot(t_stack *stack, t_node *node)
{
	t_node	*cur;

	node->next = NULL;
	if (!stack->top)
	{
		stack->top = node;
		return ;
	}
	cur = stack->top;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = node;
}

t_node	*pop_top(t_stack *stack)
{
	t_node	*removed_node;

	removed_node = stack->top;
	if (!stack->top)
		return (NULL);
	stack->top = stack->top->next;
	removed_node->next = NULL;
	return (removed_node);
}

t_node	*pop_bot(t_stack *stack)
{
	t_node	*new_bot;
	t_node	*removed;

	new_bot = stack->top;
	if (!new_bot)
		return (NULL);
	if (!new_bot->next)
	{
		removed = new_bot;
		stack->top = NULL;
		return (removed);
	}
	while (new_bot->next->next != NULL)
	{
		new_bot = new_bot->next;
		removed = new_bot->next;
	}
	new_bot->next = NULL;
	return (removed);
}
