/*
TODO:
- implement sorting of stack A for size <= 3
- implement turk sort
- input validation
- memory cleanup
- malloc error
- unallowed functions (printf etc..)
- norm & cleanups
(-testing of stack operations)
*/

#include <push_swap.h>

void sort_3_or_less(t_stack *a)
{
	t_node	*node1 = a->top;
	
	if (a->size == 1 || a->size == 0) {
		return ;
	}
	else if (a->size == 2)
	{
		t_node	*node2 = node1->next;
		if(node1->data > node2->data)
			sa(a);
		return ;
	}
	else
	{
		t_node	*node2 = node1->next;
		t_node	*node3 = node2->next;
		while (node1->data > node2->data)
		{
			sa(a);
			if(node1->data > node3->data)
			{
				ra(a);
				return;
			}
			if(node2->data > node3->data)
			{
				ra(a);
				// print_stack(a);
				sa(a);
				return;
			}
			else
				return;
		}
		while (node1->data <= node2->data)
		{
			if(node1->data > node3->data)
			{
				ra(a);
				return;
			}
			if(node2->data > node3->data)
			{
				ra(a);
				sa(a);
				return;
			}
			else
				return;
		}
	}
}

// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1

int main(int ac, char *av[])
{
	t_stack *a = init(ac, av);
	t_stack *b = new_empty_stack();
	while (a->size > 3)
	{
		pb(a,b);

	}
	sort_3_or_less(a);
	print_stack(a);


	// while (b)
	// {
	// 	//do smth
	// }
	
	
	
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