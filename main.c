/*
TODO:
[*] implement sorting of stack A for size <= 3
[ ] implement turk sort
	[*] find smallest bigger node; 
	[*] target finder;
		[*] deal with the biggest node situation;
	[*] caculate "to top cost" with index && find the cheapest node;
	[ ] use operations to get cheapest node to the top
	[ ] use operations to get cheapest node's target_node to the top

[ ] get cheapest node to a
[ ] some kind of loop?
[ ]input validation
[ ]memory cleanup
[ ]malloc error
[ ]unallowed functions (printf etc..)
[ ]norm & cleanups
([ ]testing of stack operations)
*/

#include <push_swap.h>
#include <assert.h> //

void	sort_3_or_less(t_stack *a);
t_node	*find_smallest(t_stack *a);

void	turk_sort(t_stack *a)
{
	int		target_int;
	t_stack	*b;
	t_node	*am_the_cheapest_node;
	int		index_compare;

	b = new_empty_stack();
	index_compare = 0;
	while (a->size > 3)
		pb(a, b);
	printf("a after pb: ");
	print_stack(a);
	sort_3_or_less(a);
	printf("a after sort 3: "); print_stack(a);
	printf("b after a sort 3: "); print_stack(b);
	while (b->size)
{
	target_node_finder(a, b);
	get_cost(a);
	get_cost(b);
	get_total_cost(b);
	printf("after get_costs\n");
	am_the_cheapest_node = find_cheapest_cost_in_total(b);
	while (am_the_cheapest_node->index != 0)
	{
		if (am_the_cheapest_node->index <= b->size / 2)
		{
			rrb(b);
		}
		else
		{
			rb(b);
		}
		printf("b idx: %d\n", am_the_cheapest_node->index);
	}
	print_stack(a);
	while (am_the_cheapest_node->target_in_a->index != 0)
	{
		if (am_the_cheapest_node->index <= b->size / 2)
		{
			rra(a);
		}
		else
		{
			ra(a);
		}
		// print_stack(a);
		// printf("a idx: %d\n", am_the_cheapest_node->target_in_a->index);
	}
	printf("b after rotate b(target node should be on top): ");
	print_stack_with_target_node(a);
	print_stack_with_target_node(b);
	pa(a, b);
}
	t_node *smallest = find_smallest(a);
	if (smallest->index < a->size / 2)
	{
		while (smallest->index)
			rra(a);
	}
	else
	{
		while (smallest->index)
			ra(a);	
	}
	printf("end");
	print_stack_with_target_node(a);
	print_stack_with_target_node(b);

	// while ()
	// {
	// }
}

void	sort_3_or_less(t_stack *a)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;

	node1 = a->top;
	node2 = node1->next;
	if (a->size == 1 || a->size == 0)
	{
		return ;
	}
	else if (a->size == 2)
	{
		if (node1->data > node2->data)
			sa(a);
		return ;
	}
	else
	{
		node3 = node2->next;
		while (node1->data > node2->data)
		{
			sa(a);
			if (node1->data > node3->data)
			{
				ra(a);
				return ;
			}
			if (node2->data > node3->data)
			{
				ra(a);
				sa(a);
				return ;
			}
			else
				return ;
		}
		while (node1->data <= node2->data)
		{
			if (node1->data > node3->data)
			{
				ra(a);
				return ;
			}
			if (node2->data > node3->data)
			{
				ra(a);
				sa(a);
				return ;
			}
			else
				return ;
		}
	}
}

/*
Finds the target node for a node in stack b (b_node) in stack a;
A target node(cur_node_in_a) should be:
	1. bigger than the node(b_node).
	2. the smallest one among nodes that matches condition
Each node in stack b has one target node in stack a.
If the node in stack b is the biggest, the target node is the smallest node in a.
*/
void	target_node_finder(t_stack *a, t_stack *b)
{
	t_node	*b_node_cur;
	t_node	*target_node;

	b_node_cur = b->top;
	while (b && b_node_cur)
	{
		target_node = find_smallest_bigger(a, b_node_cur->data);
		if (target_node == NULL)
			target_node = find_smallest(a);
		printf("target: %d\n ", target_node->data);
		printf("b node: %d\n", b_node_cur->data);
		assert(target_node);
		b_node_cur->target_in_a = target_node;
		b_node_cur = b_node_cur->next;
	}
	printf("fin target node finder\n");
}

// find the first smallest node in the given stack
t_node	*find_smallest(t_stack *a)
{
	t_node	*node = a->top;
	t_node	*min = a->top;
	assert(a->top);
	while (a && node)
	{
		if(node->data < min->data)
			min = node;
		node = node->next;
	}
	assert(min);
	return min;
}

t_node	*find_smallest_bigger(t_stack *a, int val)
{
	t_node	*node;
	t_node	*min;
	t_node	*empty;

	node = a->top;
	min = NULL;
	empty = a->top;
	while (empty && empty->data < val)
		empty = empty->next;
	if (!empty)
		return (NULL);
	while (node)
	{
		if (node->data > val)
		{
			if (!min || node->data < min->data)
				min = node;
		}
		node = node->next;
	}
	printf("val: %d, min: %d\n", val, min->data);
	return (min);
}

// calculate the cost to get to the top of the stack
void	get_cost(t_stack *b)
{
	int	cost = b->top->cost;
	t_node *node;

	node = b->top;
	while (b && node)
	{
		if (node->index <= b->size / 2)
		{
			cost = node->index;
			node = node->next;
		}
		else
		{
			cost = b->size - node->index;
			node = node->next;
		}
	}
}

/* calculate the total cost (cost to get to the top of the stack and 
	cost of the target note for each node in stack b to get to the top of 
	the stack)
*/
void	get_total_cost(t_stack *b)
{
	t_node *node;

	node = b->top;
	while (b && node)
	{
		assert(node->target_in_a);
		node->total_cost = node->cost + node->target_in_a->cost;
		node = node->next;
	}
}

t_node	*find_cheapest_cost_in_total(t_stack *b)
{
	t_node	*node = b->top;
	t_node	*cheapest_node = b->top;
	while (b && node)
	{
		if (node->total_cost < cheapest_node->total_cost)
			cheapest_node = node;
		node = node->next;
	}
	printf("fin find_cheapest_cost_in_total\n");
	return (cheapest_node);
}

int	main(int ac, char *av[])
{
	t_stack *a = init(ac, av);


	
	turk_sort(a);
	print_stack(a);

	//test_push_bot();
	//test_pa();
	// t_node *list = some_list();

	// print_list(list);

	// t_stack stack;
	// stack->top = list;
// 	printf("sizeof(char) = %d\n", sizeof(char));
// 	printf("sizeof(int) = %d\n", sizeof(int));
// 	printf("sizeof(t_node) = %d\n", sizeof(t_node));
// 	printf("sizeof(t_node *) = %d\n", sizeof(t_node*));

// 	printf("offset of data: %zu\n", offsetof(t_node, data));  // 0
// 	printf("offset of next: %zu\n", offsetof(t_node, next));  // 8


// 	t_node arr[10];
// 	t_node *ptr = arr;

// 	printf("arr ptr: %p (%llu)\n", ptr, (uintptr_t)ptr);

// 	printf("arr ptr + 1: %p (%llu)\n", ptr + 1, (uintptr_t)(ptr+1));
}