/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qianshuyin <qianshuyin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:29:58 by qianshuyin        #+#    #+#             */
/*   Updated: 2026/05/10 14:39:59 by qianshuyin       ###   ########.fr       */
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
	[*]norm
	[*]unallowed functions (printf etc..)
	[*]split fuctions(<= 25 lines)
	[*]makefile 打印清洁🧹
[*]import commmit history
[*]add README
[ ]remove test.c && checker_OS && make fclean etc.
[ ]add function comments
*/

#include <push_swap.h>

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
