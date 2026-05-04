/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qianshuyin <qianshuyin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:29:58 by qianshuyin        #+#    #+#             */
/*   Updated: 2026/05/04 04:30:46 by qianshuyin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
TODO:
[*] implement sorting of stack A for size <= 3
[ ] implement turk sort
	[*] find smallest bigger node; 
	[*] target finder;
		[*] deal with the biggest node situation;
	[*] caculate "to top cost" with index && find the cheapest node;
	[*] use operations to get cheapest node to the top
	[*] use operations to get cheapest node's target_node to the top

[*]input validation
[*]memory cleanup
[*]malloc error
[*]norm & cleanups
[*]unallowed functions (printf etc..)
[ ]remove test.c
[ ]import commmit history
[ ]add README
[ ]prepare for eval
([ ]testing of stack operations)
*/

#include <push_swap.h>

void	free_stack(t_stack *s)
{
	t_node	*node;
	t_node	*previous;

	if (!s)
		return ;
	if (!s->top)
	{
		free(s);
		return ;
	}
	node = s->top;
	while (node->next)
	{
		previous = node;
		node = node->next;
		free(previous);
	}
	free(node);
	free(s);
}

bool	is_sorted(t_stack *a)
{
	t_node	*node;
	t_node	*node_compare;

	node = a->top;
	node_compare = node->next;
	if (!node_compare)
		return (true);
	while (node_compare && node->data < node_compare->data)
	{
		node = node->next;
		node_compare = node->next;
	}
	if (!node_compare)
		return (true);
	return (false);
}

int	main(int ac, char *av[])
{
	t_stack	*a;

	a = init(ac, av);
	if (!a)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (has_error(ac, av, a))
	{
		ft_printf("Error\n");
		free_stack(a);
		return (1);
	}
	if (is_sorted(a) == true)
	{
		free_stack(a);
		return (0);
	}
	turk_sort(a);
	free_stack(a);
	return (0);
}
