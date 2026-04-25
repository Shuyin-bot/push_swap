#include <push_swap.h>

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
	update_size_index(a);
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
	update_size_index(b);
}

// rr : ra and rb at the same time.
void rr(t_stack *a, t_stack *b) {
	if ((!a->top||a->top->next==NULL)&&(!b->top||b->top->next==NULL))
		return;
	rb_base(a, false);
	rb_base(b, false);
	printf("rr\n");
	update_size_index(a);
	update_size_index(b);
}
