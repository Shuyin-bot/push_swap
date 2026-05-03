/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qianshuyin <qianshuyin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:34:28 by qianshuyin        #+#    #+#             */
/*   Updated: 2026/05/03 19:50:36 by qianshuyin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
	return (min);
}

// calculate the cost to get to the top of the stack
void	get_cost(t_stack *b)
{
	int		cost;
	t_node	*node;

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
	t_node	*node;

	node = b->top;
	while (b && node)
	{
		node->total_cost = node->cost + node->target_in_a->cost;
		node = node->next;
	}
}

t_node	*find_cheapest_cost_in_total(t_stack *b)
{
	t_node	*node;
	t_node	*cheapest_node;

	node = b->top;
	cheapest_node = b->top;
	while (b && node)
	{
		if (node->total_cost < cheapest_node->total_cost)
			cheapest_node = node;
		node = node->next;
	}
	return (cheapest_node);
}

void	print_stack(t_stack *stack)
{
	t_node	*cur;

	cur = stack->top;
	ft_printf("{");
	while (cur)
	{
		if (cur->next)
			ft_printf("%d, ", cur->data);
		else
			ft_printf("%d", cur->data);
		cur = cur->next;
	}
	ft_printf("}\n");
}
