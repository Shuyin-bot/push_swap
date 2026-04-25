#include <push_swap.h>

// rra (reverse rotate a): Shift down all elements of stack a by 1.
//The last element becomes the first one.
//  a->top->next!= 0 same as  (*a).top->next!= 0
void rra(t_stack *a) {
	t_node  *node;
	if (a && a->top && a->top->next!= 0)
	{
		node = pop_bot(a);
		push_top(a, node);
		update_size_index(a);
		printf("rra\n");
	}
	return ;
}

void rrb_base(t_stack *b, bool print)
{
	t_node  *node;
	if (b && b->top && b->top->next!= 0)
	{
		node = pop_bot(b);
		push_top(b, node);
		if (print)
		{
			update_size_index(b);
			printf("rrb\n");
		}
	}
	return ;
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
//The last element becomes the first one.
void rrb(t_stack *b) {
	rrb_base(b, 1);
}

// rrr : rra and rrb at the same time.
void rrr(t_stack *a, t_stack *b) {
	rrb_base(a, 0);
	rrb_base(b, 0);
	update_size_index(a);
	update_size_index(b);
	printf("rrr\n");
}
