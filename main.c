#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_node t_node;

typedef struct s_node {
	t_node *next;
	int data;
} t_node;

typedef struct s_stack {
	t_node *top;
} t_stack;


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

t_node *pop_top(t_stack *stack){
	t_node *removed_node;

	removed_node = stack->top;
	if (!stack->top)
		return NULL;
	stack->top = stack->top->next;
	removed_node->next = NULL;
	return (removed_node);
}

t_node *pop_bot(t_stack *stack){
	t_node *new_bot = stack->top;
	t_node *removed;
	if (!new_bot)
		return NULL;
	if (!new_bot->next) {
		removed = new_bot;
		stack->top = NULL;
		return removed;
	}
	while (new_bot->next->next != NULL)
		new_bot = new_bot->next;
	removed = new_bot->next;
	new_bot->next = NULL;
	return removed;
	}


void push_top(t_stack *stack, t_node *node) {
	t_node *old_top = stack->top;
	//t_node *list;	
	//list = node;
	//stack->top = list;
	stack->top = node;
	stack->top->next = old_top;
}
void push_bot(t_stack *stack, t_node *node){	
	node->next = NULL;
	if (!stack->top) {
		stack->top = node;
		return ;
	}
	t_node	*cur = stack->top;
	while(cur->next != NULL)
		cur = cur->next;
	cur->next = node;
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

void rb_base(t_stack *b, bool print) {
	t_node *first_node = pop_top(b);
	if (!first_node ||first_node->next == NULL){
		return;
	}
	push_bot(b, first_node);
	if (print)
		printf("rb\n");
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

bool stacks_eq(t_stack *stack_a, t_stack *stack_b) {
	// int arr_a[2] = {1, 2};
	// int arr_b[2] = {1, 2};
	// int len = 2;
	// int i = 0;
	// 	while (i < len && arr_a[i] == arr_b[i])
	// 		i++;
	// 	if (i < len)
	// 		return false;
	// return true;

	t_node *list_a = stack_a->top;
	t_node *list_b = stack_b->top;

	t_node	*cur_a = list_a;
	t_node	*cur_b = list_b;

	while (cur_a && cur_b)
	{
		if (cur_a->data != cur_b->data)
			return false;
		cur_a = cur_a->next;
		cur_b = cur_b->next;
	}
	if (cur_a != cur_b)
		return false;
	return true;
}

void print_list(t_node *list) {
	t_node *cur = list;
	printf("{");
	while (cur) {
		printf("%d, ", cur->data);
		cur = cur->next;
	}
	printf("}\n");
}

void print_stack(t_stack *stack) {
	print_list(stack->top);
}

// alloctates a node and pushes it on the stack with the given int
void push_int(t_stack *s, int i) {
	t_node	*node = malloc(sizeof(t_node));
	node->data = i;
	push_bot(s, node);
}

t_stack *dumy_stack0() {
	return calloc(1, sizeof(t_stack));
}
t_stack *dumy_stack1() {
	t_stack *s = malloc(sizeof (t_stack));
	s->top = NULL;
	push_int(s, 1);
	return s;
}

t_stack *dumy_stack2() {
	t_stack *s = malloc(sizeof (t_stack));
	s->top = NULL;
	push_int(s, 1);
	push_int(s, 2);
	return s;
}
t_stack *dumy_stack3() {
	t_stack *s = malloc(sizeof (t_stack));
	s->top = NULL;
	push_int(s, 1) ;
	push_int(s, 2);
	push_int(s, 3);
	return s;
}

void	test_push_bot() {
	t_stack *s0 = dumy_stack0();
	printf("expected: {}\n");
	print_stack(s0);

	t_stack *s1 = dumy_stack1();
	printf("expected: {1, }\n");
	print_stack(s1);
	
	t_stack *s2 = dumy_stack2();
	printf("expected: {1, 2, }\n");
	print_stack(s2);
	
	t_stack *s3 = dumy_stack3();
	printf("expected: {1, 2, 3, }\n");
	print_stack(s3);
}

t_stack *make_stack(int *content, int content_len) {
	int i = 0;
	t_stack *stack = malloc(sizeof(t_stack));
	stack->top = NULL;
	while (i < content_len)
	{
		push_int(stack, content[i]);
		i++;
	}
	return stack;
}

void test_pa() {
	t_stack *a = dumy_stack3();
	t_stack *b = dumy_stack0();
	pa(a, b);
	int expected_int[] = {1, 2, 3};
	t_stack *expected_a = make_stack(expected_int, 3);
	int expected_intb[] = {};
	t_stack *expected_b = make_stack(expected_intb, 0);
	if (!stacks_eq(a, expected_a) || !stacks_eq(b, expected_b)) {
		fprintf(stderr, "TEST pa FAILED\n");
		//todo better output of what failed
	} else {
		printf("test pa passed\n");
	}
}

#include <stddef.h>
#include <stdint.h>
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