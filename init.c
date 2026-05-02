/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qianshuyin <qianshuyin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:32:35 by qianshuyin        #+#    #+#             */
/*   Updated: 2026/05/02 19:37:51 by qianshuyin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*new_empty_stack(void)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	update_size_index(stack);
	return (stack);
}

// alloctates a node and pushes it on the stack with the given int
static void	push_int(t_stack *s, int i)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	node->data = i;
	push_bot(s, node);
}

t_stack	*init(int ac, char *av[])
{
	int		i;
	int		val;
	t_stack	*a;

	i = 1;
	a = new_empty_stack();
	while (i < ac)
	{
		val = ft_atoi(av[i]);
		push_int(a, val);
		i++;
	}
	update_size_index(a);
	return (a);
}
