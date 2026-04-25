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


int ft_stacklen(t_stack *stack)
{
	int len = 0;
	t_node  *node = stack->top;
	while (stack && node)
	{
		len++;
		node = node->next;
	}
	return (len);
}

int main(int ac, char *av[])
{
	t_stack *a = init(ac, av);
	t_stack *b = new_empty_stack();
	while (a->size > 3)
	{
		pb(a,b);

	}

	while (b)
	{
		//do smth
	}
	
	
	
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