/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qianshuyin <qianshuyin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 19:50:51 by qianshuyin        #+#    #+#             */
/*   Updated: 2026/05/10 14:44:08 by qianshuyin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_stack	*init_from_str(t_stack *a, char *str);
static bool	push_int(t_stack *s, int i);

t_stack	*init(int ac, char *av[])
{
	int		i;
	int		val;
	t_stack	*a;

	a = new_empty_stack();
	if (!a)
		return (NULL);
	if (ac == 2)
		return (init_from_str(a, av[1]));
	i = 1;
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

t_stack	*new_empty_stack(void)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	update_size_index(stack);
	return (stack);
}

static t_stack	*init_from_str(t_stack *a, char *str)
{
	char	**sp;
	int		i;

	sp = ft_split(str, ' ');
	if (!sp)
	{
		free_stack(a);
		return (NULL);
	}
	i = 0;
	while (sp[i])
	{
		if (!push_int(a, ft_atoi(sp[i])))
		{
			free_strs(sp);
			free_stack(a);
			return (NULL);
		}
		i++;
	}
	free_strs(sp);
	update_size_index(a);
	return (a);
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
