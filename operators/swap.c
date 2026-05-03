/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qianshuyin <qianshuyin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 05:26:23 by qianshuyin        #+#    #+#             */
/*   Updated: 2026/05/03 19:48:45 by qianshuyin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// sa (swap a): Swap the first 2 elements at the top of stack a->
//Do nothing if there is only one element or none.
void	sa(t_stack *a)
{
	t_node	*list;
	int		temp1;

	list = a->top;
	if (!list || list->next == NULL)
	{
		return ;
	}
	temp1 = list->data;
	list->data = list->next->data;
	list->next->data = temp1;
	ft_printf("sa\n");
	update_size_index(a);
}

// sb (swap b): Swap the first 2 elements at the top of stack b->
//Do nothing if there is only one element or none.
void	sb(t_stack *b)
{
	t_node	*list;
	int		temp1;
	bool	not_swap;

	list = b->top;
	not_swap = !list || list->next == NULL;
	if (not_swap)
		return ;
	temp1 = list->data;
	list->data = list->next->data;
	list->next->data = temp1;
	ft_printf("sb\n");
	update_size_index(b);
}

// ss : sa and sb at the same time.
void	ss(t_stack *a, t_stack *b)
{
	t_node	*list_a;
	int		temp;
	bool	swap_a;
	bool	swap_b;

	list_a = a->top;
	swap_a = list_a && list_a->next != NULL;
	swap_b = b->top && b->top->next != NULL;
	if (swap_a)
	{
		temp = list_a->data;
		list_a->data = list_a->next->data;
		list_a->next->data = temp;
	}
	if (swap_b)
	{
		temp = b->top->data;
		b->top->data = b->top->next->data;
		b->top->next->data = temp;
	}
	if (swap_a || swap_b)
		ft_printf("ss\n");
	update_size_index(a);
	update_size_index(b);
}
