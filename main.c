/*
TODO:
[*] implement sorting of stack A for size <= 3
[ ] implement turk sort
	[*] find smallest bigger node; 
	[*] target finder;
		[ ] deal with the biggest node situation;
	[ ] caculate "to top cost" with index && find the cheapest node;
[ ]input validation
[ ]memory cleanup
[ ]malloc error
[ ]unallowed functions (printf etc..)
[ ]norm & cleanups
([ ]testing of stack operations)
*/

#include <push_swap.h>

void	sort_3_or_less(t_stack *a);

void	turk_sort(t_stack *a)
{
	int		target_int;
	t_stack	*b;

	b = new_empty_stack();
	while (a->size > 3)
		pb(a, b);
	sort_3_or_less(a);
	target_node_finder(a, b);
	print_stack_with_target_node(b);
}

void	sort_3_or_less(t_stack *a)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;

	node1 = a->top;
	if (a->size == 1 || a->size == 0)
	{
		return ;
	}
	else if (a->size == 2)
	{
		node2 = node1->next;
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
		b_node_cur->target_in_a = target_node;
		b_node_cur = b_node_cur->next;
	}
}

// find 

t_node	*find_smallest_bigger(t_stack *a, int val)
{
	t_node	*node;
	t_node	*min;
	t_node	*empty;

	node = a->top;
	min = a->top;
	while (empty && empty->data < val)
		empty = empty->next;
	if (!empty)
		return (NULL);
	while (node)
	{
		if (node->data > val)
		{
			if (node->data < min->data)
				min = node;	
		}
		node = node->next;
	}
	return (min);
}

int	main(int ac, char *av[])
{
	t_stack *a = init(ac, av);
	// t_stack	*b = new_empty_stack();
	// t_node	*smallest_bigger;
	// int		*target_int;
	// int		val = 5;
	// smallest_bigger = find_smallest_bigger(a, val);
	// printf("smalllest bigger: %d\n", smallest_bigger->data);
	
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