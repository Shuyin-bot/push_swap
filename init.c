/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qianshuyin <qianshuyin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:32:35 by qianshuyin        #+#    #+#             */
/*   Updated: 2026/05/03 19:09:43 by qianshuyin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*new_empty_stack(void)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	update_size_index(stack);
	return (stack);
}

// alloctates a node and pushes it on the stack with the given int
static bool	push_int(t_stack *s, int i)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (false);
	node->data = i;
	push_bot(s, node);
	return (true);
}

t_stack	*init(int ac, char *av[])
{
	int		i;
	int		val;
	t_stack	*a;

	i = 1;
	a = new_empty_stack();
	if (!a)
		return (NULL);
	while (i < ac)
	{
		val = ft_atoi(av[i]);
		if (push_int(a, val) == false)
		{
			free_stack(a);
			return (NULL);
		}
		i++;
	}
	update_size_index(a);
	return (a);
}
