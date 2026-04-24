/*
TODO:
- finish stack operations
- implement sorting of stack A for size <= 3
- implement turk sort
- input parsing
- memory cleanup
- unallowed functions (printf etc..)
- norm & cleanups
(-testing of stack operations)
*/

#include <push_swap.h>

// sa (swap a): Swap the first 2 elements at the top of stack a->
//Do nothing if there is only one element or none.
void sa(t_stack *a) {
	t_node *list = a->top;
	int	temp1;

	if(!list || list->next == NULL){
		return ;
	}
	temp1 = list->data;	
	list->data = list->next->data;
	list->next->data = temp1;
	printf("sa\n");
}

// sb (swap b): Swap the first 2 elements at the top of stack b->
//Do nothing if there is only one element or none.
void sb(t_stack *b) {
	t_node *list = b->top;
	int	temp1;

	bool not_swap = !list || list->next == NULL;
	if(not_swap){
		return ;
	}
	temp1 = list->data;	
	list->data = list->next->data;
	list->next->data = temp1;
	printf("sb\n");
}

// ss : sa and sb at the same time.
void ss(t_stack *a, t_stack *b) {
	t_node *list_a = a->top;
	t_node *list_b = b->top;
	int	temp;

	bool swap_a = list_a && list_a->next != NULL;
	bool swap_b = list_b && list_b->next != NULL;

	if (swap_a) {
	temp = list_a->data;	
	list_a->data = list_a->next->data;
	list_a->next->data = temp;
	}
	if (swap_b) {
	temp = list_b->data;	
	list_b->data = list_b->next->data;
	list_b->next->data = temp;
	}
	if (swap_a || swap_b)
		printf("ss\n");

}

// pa (push a): Take the first element at the top of b and put it at the top of a->
// Do nothing if b is empty.
void pa(t_stack *a, t_stack *b){
	t_node	*node;
	if (!b->top)
		return ;
	node = pop_top(b);
	push_top(a, node);
	printf("pa\n");
}

// pb (push b): Take the first element at the top of a and put it at the top of b->
// Do nothing if a is empty.
void pb(t_stack *a, t_stack *b){
	t_node	*node;
	if (!a->top)
		return ;
	node = pop_top(a);
	push_top(b, node);
	printf("pb\n");
}

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void ra(t_stack *a) {
	t_node *first_node = pop_top(a);
	
	// int arr[2] = {1,2};
	// int *ptr = arr;
	// ptr[1];
	// *(ptr + 1);

	// first_node->data;
	// *((long long*)first_node + 1);
	
	if (!first_node || first_node->next == NULL){
		return;
	}
	push_bot(a, first_node);
	printf("ra\n");
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void rb(t_stack *b) {
	rb_base(b, true);
}

// rr : ra and rb at the same time.
void rr(t_stack *a, t_stack *b) {
	if ((!a->top||a->top->next==NULL)&&(!b->top||b->top->next==NULL))
		return;
	rb_base(a, false);
	rb_base(b, false);
	printf("rr\n");
}


// rra (reverse rotate a): Shift down all elements of stack a by 1.
//The last element becomes the first one.
void rra(t_stack *stack) {
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
//The last element becomes the first one.
void rrb(t_stack *stack) {
}

// rrr : rra and rrb at the same time.
void rrr(t_stack *stack) {
}

int main(int ac, char *av[])
{
	//test_push_bot();
	test_pa();
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