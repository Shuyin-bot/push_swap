/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qianshuyin <qianshuyin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:03:28 by qianshuyin        #+#    #+#             */
/*   Updated: 2026/05/03 19:24:56 by qianshuyin       ###   ########.fr       */
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

bool	valid_int_range_negative(char *str)
{
	const char	max[] = "2147483648";
	int			i;

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

bool	valid_int_range_positive(char *str)
{
	const char	max[] = "2147483647";
	int			i;

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
	if (negative && !valid_int_range_negative(str))
		return (false);
	else if (!negative && !valid_int_range_positive(str))
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (false);
	}
	return (true);
}

// check each str arguement if has valid input or duplicate case
bool	has_error(int argc, char **argv, t_stack *a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!valid_input(argv[i++]))
			return (true);
	}
	if (has_duplicates(a))
		return (true);
	return (false);
}
