/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qianshuyin <qianshuyin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:41:41 by qianshuyin        #+#    #+#             */
/*   Updated: 2026/04/30 19:36:24 by qianshuyin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ra(t_stack *a)
{
	t_node	*node;

	if (a && a->top && a->top->next != 0)
	{
		node = pop_bot(a);
		push_top(a, node);
		update_size_index(a);
		printf("ra\n");
	}
	return ;
}

void	rb_base(t_stack *b, bool print)
{
	t_node	*node;

	if (b && b->top && b->top->next != 0)
	{
		node = pop_bot(b);
		push_top(b, node);
		if (print)
		{
			update_size_index(b);
			printf("rb\n");
		}
	}
	return ;
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(t_stack *b)
{
	rb_base(b, 1);
	update_size_index(b);
}

// rr : ra and rb at the same time.
void	rr(t_stack *a, t_stack *b)
{
	rb_base(a, 0);
	rb_base(b, 0);
	update_size_index(a);
	update_size_index(b);
	printf("rr\n");
}
