/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qianshuyin <qianshuyin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:38:39 by qianshuyin        #+#    #+#             */
/*   Updated: 2026/05/03 18:00:32 by qianshuyin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft/libft.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
#include <assert.h> //

typedef struct s_node	t_node;

typedef struct s_node
{
	t_node	*next;
	int		index;
	int		data;
	t_node	*target_in_a;
	int		cost;
	int		total_cost;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

//11 operators
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *a, t_stack *b);

//init
t_stack	*new_empty_stack(void);
t_stack	*init(int ac, char *av[]);

//utility && test
void	sort_3_or_less(t_stack *a);
void	push_top(t_stack *stack, t_node *node);
void	push_bot(t_stack *stack, t_node *node);
t_node	*pop_top(t_stack *stack);
t_node	*pop_bot(t_stack *stack);
void	update_size_index(t_stack *stack);
void	rb_base(t_stack *b, bool print);
void	rrb_base(t_stack *b, bool print);
void	print_stack(t_stack *stack);
void	print_stack_with_target_node(t_stack *b);
t_node	*find_smallest(t_stack *a);
t_node	*find_smallest_bigger(t_stack *a, int val);
void	target_node_finder(t_stack *a, t_stack *b);
void	get_cost(t_stack *b);
void	get_total_cost(t_stack *b);
t_node	*find_cheapest_cost_in_total(t_stack *b);
bool	has_error(int argc, char **argv, t_stack *a);
void	free_stack(t_stack *s);
bool	is_sorted(t_stack *a);

#endif