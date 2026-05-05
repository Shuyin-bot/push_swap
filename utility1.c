/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qianshuyin <qianshuyin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 19:50:51 by qianshuyin        #+#    #+#             */
/*   Updated: 2026/05/04 05:39:38 by qianshuyin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	update_size_index(t_stack *stack)
{
	t_node	*node;
	int		cur_index;

	node = stack->top;
	cur_index = 0;
	while (stack && node)
	{
		node->index = cur_index;
		node = node -> next;
		cur_index++;
	}
	stack->size = cur_index;
}

static void	sort_exactly_3(t_stack *a)
{
	if (a->top->data < a->top->next->next->data
		&& a->top->next->data > a->top->next->next->data)
	{
		ra(a);
		sa(a);
		rra(a);
		return ;
	}
	if (a->top->data > a->top->next->next->data
		&& a->top->next->data < a->top->next->next->data)
	{
		ra(a);
		return ;
	}
	if (a->top->data > a->top->next->data)
		sa(a);
	if (is_sorted(a))
		return ;
	if (a->top->next->next->data < a->top->data)
		rra(a);
	else
		ra(a);
}

void	sort_3_or_less(t_stack *a)
{
	t_node	*node1;
	t_node	*node2;

	node1 = a->top;
	node2 = node1->next;
	if (a->size == 1 || a->size == 0)
	{
		return ;
	}
	else if (a->size == 2)
	{
		if (node1->data > node2->data)
			sa(a);
		return ;
	}
	else
		sort_exactly_3(a);
}

/*
Finds the target node for a node in stack b (b_node) in stack a;
A target node(cur_node_in_a) should be:
	1. bigger than the node(b_node).
	2. the smallest one among nodes that matches condition
Each node in stack b has one target node in stack a.
If the node in stack b is the biggest, the target node is the smallest node in a.
*/
void	target_node_finder(t_stack *a, t_stack *b)
{
	t_node	*b_node_cur;
	t_node	*target_node;

	b_node_cur = b->top;
	while (b && b_node_cur)
	{
		target_node = find_smallest_bigger(a, b_node_cur->data);
		if (target_node == NULL)
			target_node = find_smallest(a);
		b_node_cur->target_in_a = target_node;
		b_node_cur = b_node_cur->next;
	}
}

// find the first smallest node in the given stack
t_node	*find_smallest(t_stack *a)
{
	t_node	*node;
	t_node	*min;

	node = a->top;
	min = a->top;
	while (a && node)
	{
		if (node->data < min->data)
			min = node;
		node = node->next;
	}
	return (min);
}
