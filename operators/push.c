/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qianshuyin <qianshuyin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 05:37:54 by qianshuyin        #+#    #+#             */
/*   Updated: 2026/05/03 19:48:26 by qianshuyin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// pa (push a): Take first element at the top of b and put it at the top of a->
// Do nothing if b is empty.
void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!b->top)
		return ;
	node = pop_top(b);
	push_top(a, node);
	update_size_index(a);
	update_size_index(b);
	ft_printf("pa\n");
}

// pb (push b): Take first element at the top of a and put it at the top of b->
// Do nothing if a is empty.
void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!a->top)
		return ;
	node = pop_top(a);
	push_top(b, node);
	update_size_index(a);
	update_size_index(b);
	ft_printf("pb\n");
}
