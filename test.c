#include <push_swap.h>

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