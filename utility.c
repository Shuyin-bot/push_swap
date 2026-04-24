#include <push_swap.h>

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

void rb_base(t_stack *b, bool print) {
	t_node *first_node = pop_top(b);
	if (!first_node ||first_node->next == NULL){
		return;
	}
	push_bot(b, first_node);
	if (print)
		printf("rb\n");
}
