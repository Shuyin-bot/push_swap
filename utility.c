/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qianshuyin <qianshuyin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 19:50:51 by qianshuyin        #+#    #+#             */
/*   Updated: 2026/05/03 18:58:58 by qianshuyin       ###   ########.fr       */
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

void	sort_exactly_3(t_stack *a)
{
	if (a->top->data < a->top->next->next->data && a->top->next->data > a->top->next->next->data)
	{
		ra(a);
		sa(a);
		rra(a);
		return ;
	}
	if (a->top->data > a->top->next->next->data && a->top->next->data < a->top->next->next->data)
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
		// printf("target: %d\n ", target_node->data);
		// printf("b node: %d\n", b_node_cur->data);
		assert(target_node);
		b_node_cur->target_in_a = target_node;
		b_node_cur = b_node_cur->next;
	}
	// printf("fin target node finder\n");
}

// find the first smallest node in the given stack
t_node	*find_smallest(t_stack *a)
{
	t_node	*node = a->top;
	t_node	*min = a->top;
	assert(a->top);
	while (a && node)
	{
		if(node->data < min->data)
			min = node;
		node = node->next;
	}
	assert(min);
	return min;
}

t_node	*find_smallest_bigger(t_stack *a, int val)
{
	t_node	*node;
	t_node	*min;
	t_node	*empty;

	node = a->top;
	min = NULL;
	empty = a->top;
	while (empty && empty->data < val)
		empty = empty->next;
	if (!empty)
		return (NULL);
	while (node)
	{
		if (node->data > val)
		{
			if (!min || node->data < min->data)
				min = node;
		}
		node = node->next;
	}
	// printf("val: %d, min: %d\n", val, min->data);
	return (min);
}

// calculate the cost to get to the top of the stack
void	get_cost(t_stack *b)
{
	int	cost = b->top->cost;
	t_node *node;

	node = b->top;
	while (b && node)
	{
		if (node->index <= b->size / 2)
		{
			cost = node->index;
		}
		else
		{
			cost = b->size - node->index;
		}
		node->cost = cost;
			node = node->next;
	}
}

/* calculate the total cost (cost to get to the top of the stack and 
	cost of the target note for each node in stack b to get to the top of 
	the stack)
*/
void	get_total_cost(t_stack *b)
{
	t_node *node;

	node = b->top;
	while (b && node)
	{
		assert(node->target_in_a);
		node->total_cost = node->cost + node->target_in_a->cost;
		node = node->next;
	}
}

t_node	*find_cheapest_cost_in_total(t_stack *b)
{
	t_node	*node = b->top;
	t_node	*cheapest_node = b->top;
	while (b && node)
	{
		if (node->total_cost < cheapest_node->total_cost)
			cheapest_node = node;
		node = node->next;
	}
	// printf("fin find_cheapest_cost_in_total\n");
	return (cheapest_node);
}
