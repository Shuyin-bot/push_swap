/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qianshuyin <qianshuyin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 05:23:21 by qianshuyin        #+#    #+#             */
/*   Updated: 2026/05/03 17:37:29 by qianshuyin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// rra (reverse rotate a): Shift down all elements of stack a by 1.
//The last element becomes the first one.
//  a->top->next!= 0 same as  (*a).top->next!= 0
void	rra(t_stack *a)
{
	t_node	*first_node;

	first_node = pop_bot(a);
	if (!first_node){
		return ;
	}
	push_top(a, first_node);
	update_size_index(a);
	printf("rra\n");
}

void	rrb_base(t_stack *b, bool print)
{
	t_node	*first_node;

	if (!b->top || b->top->next == NULL)
	{
		return ;
	}
	first_node = pop_bot(b);
	push_top(b, first_node);
	if (print)
		printf("rrb\n");
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
//The last element becomes the first one.
void	rrb(t_stack *b)
{
	rrb_base(b, true);
	update_size_index(b);
}

// rrr : rra and rrb at the same time.
void	rrr(t_stack *a, t_stack *b)
{
	if ((!a->top || a->top->next == NULL) && (!b->top || b->top->next == NULL))
		return ;
	rrb_base(a, false);
	rrb_base(b, false);
	printf("rrr\n");
	update_size_index(a);
	update_size_index(b);
}
