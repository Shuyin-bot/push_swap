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

[ ]input validation
[ ]memory cleanup
[ ]malloc error
[ ]unallowed functions (printf etc..)
[ ]norm & cleanups
([ ]testing of stack operations)
*/

#include <push_swap.h>

void	sort_3_or_less(t_stack *a);
t_node	*find_smallest(t_stack *a);

void	turk_sort(t_stack *a)
{
	int		target_int;
	t_stack	*b;
	t_node	*am_the_cheapest_node;
	t_node	*smallest;
	int		index_compare;

	b = new_empty_stack();
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
				rb(b);
			}
			else
			{
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
}

int	main(int ac, char *av[])
{
	t_stack *a;

	a = init(ac, av);
	turk_sort(a);
	//print_stack(a);
}