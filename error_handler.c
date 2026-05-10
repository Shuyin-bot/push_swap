/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qianshuyin <qianshuyin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:03:28 by qianshuyin        #+#    #+#             */
/*   Updated: 2026/05/04 04:18:59 by qianshuyin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool	has_duplicates(t_stack *stack)
{
	t_node	*node;
	t_node	*node_pick;

	node_pick = stack->top;
	while (node_pick)
	{
		node = node_pick->next;
		while (node)
		{
			if (node->data == node_pick->data)
				return (true);
			node = node->next;
		}
		node_pick = node_pick->next;
	}
	return (false);
}

static bool	valid_int_range(char *str, bool negative)
{
	const char	*max;
	int			i;

	if (negative)
		max = "2147483648";
	else
		max = "2147483647";
	if (ft_strlen(max) > ft_strlen(str))
		return (true);
	if (ft_strlen(max) < ft_strlen(str))
		return (false);
	i = 0;
	while (max[i] && max[i] == str[i])
		i++;
	if (!max[i])
		return (true);
	if (max[i] < str[i])
		return (false);
	return (true);
}

bool	valid_input(char *str)
{
	int		i;
	bool	negative;

	if (!str || !str[0])
		return (true);
	i = 0;
	negative = *str == '-';
	if (*str == '-' || *str == '+')
		str++;
	if (!valid_int_range(str, negative))
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (false);
	}
	return (true);
}

static bool	has_error_str(char *str)
{
	char	**sp;
	int		i;

	sp = ft_split(str, ' ');
	if (!sp)
		return (true);
	i = 0;
	while (sp[i])
	{
		if (!valid_input(sp[i]))
		{
			free_strs(sp);
			return (true);
		}
		i++;
	}
	free_strs(sp);
	return (false);
}

bool	has_error(int argc, char **argv, t_stack *a)
{
	int	i;

	if (argc == 2)
		return (has_error_str(argv[1]) || has_duplicates(a));
	i = 1;
	while (i < argc)
	{
		if (!valid_input(argv[i++]))
			return (true);
	}
	return (has_duplicates(a));
}
