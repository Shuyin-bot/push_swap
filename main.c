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
[ ]malloc error
[ ]unallowed functions (printf etc..)
[ ]norm & cleanups
([ ]testing of stack operations)
 ('1 2 3' 4 5 6 argumet style?)
*/

#include <push_swap.h>

void	free_stack(t_stack *s)
{
	t_node *node;
	t_node *previous;

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

void	turk_sort(t_stack *a)
{
	int		target_int;
	t_stack	*b;
	t_node	*am_the_cheapest_node;
	t_node	*smallest;
	int		index_compare;

	b = new_empty_stack();
	if (!b)
	{
		printf("Error\n");
		return ;
	}
	index_compare = 0;
	while (a->size > 3)
		pb(a, b);
	sort_3_or_less(a);
	while (b->size)
	{
		target_node_finder(a, b);
		get_cost(a);
		get_cost(b);
		get_total_cost(b);
		am_the_cheapest_node = find_cheapest_cost_in_total(b);
		while (am_the_cheapest_node->index != 0)
		{
			if (am_the_cheapest_node->index <= b->size / 2)
			{
				if (am_the_cheapest_node->target_in_a->index <= a->size / 2 && am_the_cheapest_node->target_in_a->index != 0)
					rr(a, b);
				else
					rb(b);
			}
			else
			{
				if (am_the_cheapest_node->target_in_a->index > a->size / 2)
					rrr(a, b);
				else
					rrb(b);
			}
		}
		while (am_the_cheapest_node->target_in_a->index != 0)
		{
			if (am_the_cheapest_node->target_in_a->index <= a->size / 2)
			{
				ra(a);
			}
			else
			{
				rra(a);
			}
		}
		pa(a, b);
	}
	smallest = find_smallest(a);
	if (smallest->index < a->size / 2)
	{
		while (smallest->index)
			ra(a);
	}
	else
	{
		while (smallest->index)
			rra(a);
	}
	free_stack(b);
}

bool	is_sorted(t_stack *a)
{
	t_node	*node;
	t_node	*node_compare;

	node = a->top;
	node_compare = node->next;
	if (!node_compare)
		return true;
	while (node_compare && node->data < node_compare->data)
	{
		node = node->next;
		node_compare = node->next;
	}
	if (!node_compare)
		return true;
	return false;
}

int	main(int ac, char *av[])
{
	t_stack *a;

	a = init(ac, av);
	if (!a)
	{
		printf("Error\n");
		return 1;
	}
	if (has_error(ac, av, a)) {
		printf("Error\n");
		free_stack(a);
		return 1;
	}
	if (is_sorted(a) == true)
	{
		free_stack(a);
		return 0;
	}
	turk_sort(a);
	//print_stack(a);
	free_stack(a);
	return 0;
}
