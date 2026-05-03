/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qianshuyin <qianshuyin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:31:06 by qianshuyin        #+#    #+#             */
/*   Updated: 2026/05/03 20:03:20 by qianshuyin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*init_turk_sort(t_stack *a)
{
	t_stack	*b;

	b = new_empty_stack();
	if (!b)
	{
		ft_printf("Error\n");
		return (NULL);
	}
	while (a->size > 3 && !is_sorted(a))
		pb(a, b);
	sort_3_or_less(a);
	return (b);
}

void	finish_turk_sort(t_stack *a, t_stack *b)
{
	t_node	*smallest;

	smallest = find_smallest(a);
	if (smallest->index < a->size / 2)
	{
		while (smallest->index)
			ra(a);
	}
	else
	{
		while (smallest->index)
			rra(a);
	}
	free_stack(b);
}

void	turk_sort_rotate_b(t_stack *a, t_stack *b, t_node *am_the_cheapest_node)
{
	while (am_the_cheapest_node->index != 0)
	{
		if (am_the_cheapest_node->index <= b->size / 2)
		{
			if (am_the_cheapest_node->target_in_a->index <= a->size / 2
				&& am_the_cheapest_node->target_in_a->index != 0)
				rr(a, b);
			else
				rb(b);
		}
		else
		{
			if (am_the_cheapest_node->target_in_a->index > a->size / 2)
				rrr(a, b);
			else
				rrb(b);
		}
	}
}

void	turk_sort(t_stack *a)
{
	t_stack	*b;
	t_node	*am_the_cheapest_node;

	b = init_turk_sort(a);
	if (!b)
		return ;
	while (b->size)
	{
		target_node_finder(a, b);
		get_cost(a);
		get_cost(b);
		get_total_cost(b);
		am_the_cheapest_node = find_cheapest_cost_in_total(b);
		turk_sort_rotate_b(a, b, am_the_cheapest_node);
		while (am_the_cheapest_node->target_in_a->index != 0)
		{
			if (am_the_cheapest_node->target_in_a->index <= a->size / 2)
				ra(a);
			else
				rra(a);
		}
		pa(a, b);
	}
	finish_turk_sort(a, b);
}
