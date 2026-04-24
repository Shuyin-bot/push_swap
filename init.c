#include <push_swap.h>

t_stack *new_empty_stack(void) {
	t_stack *stack;
	stack = ft_calloc(1, sizeof(t_stack));
	return stack;
}

// alloctates a node and pushes it on the stack with the given int
static void push_int(t_stack *s, int i) {
	t_node	*node = ft_calloc(1, sizeof(t_node));
	node->data = i;
	push_bot(s, node);
}

t_stack *init(int ac, char *av[]) {
	int i = 1;
	int	val;
	t_stack *a = new_empty_stack();

	while (i < ac)
	{
		val = ft_atoi(av[i]);
		push_int(a, val);
		// todo: input validation
		i++;
	}
	return (a);
}