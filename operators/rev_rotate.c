/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qianshuyin <qianshuyin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 05:23:21 by qianshuyin        #+#    #+#             */
/*   Updated: 2026/04/28 05:25:22 by qianshuyin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// rra (reverse rotate a): Shift down all elements of stack a by 1.
//The last element becomes the first one.
//  a->top->next!= 0 same as  (*a).top->next!= 0
void	rra(t_stack *a)
{
	t_node	*first_node;
	// int arr[2] = {1,2};
	// int *ptr = arr;
	// ptr[1];
	// *(ptr + 1);
	
	// first_node->data;
	// *((long long*)first_node + 1);
	first_node = pop_top(a);
	if (!first_node || first_node->next == NULL){
		return ;
	}
	push_bot(a, first_node);
	update_size_index(a);
	printf("rra\n");
}

void	rrb_base(t_stack *b, bool print)
{
	t_node	*first_node;

	first_node = pop_top(b);
	if (!first_node || first_node->next == NULL)
	{
		return ;
	}
	push_bot(b, first_node);
	if (print)
		printf("rrb\n");
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
//The last element becomes the first one.
void	rrb(t_stack *b)
{
	rb_base(b, true);
	update_size_index(b);
}

// rrr : rra and rrb at the same time.
void	rrr(t_stack *a, t_stack *b)
{
	if ((!a->top || a->top->next == NULL) && (!b->top || b->top->next == NULL))
		return ;
	rb_base(a, false);
	rb_base(b, false);
	printf("rrr\n");
	update_size_index(a);
	update_size_index(b);
}
