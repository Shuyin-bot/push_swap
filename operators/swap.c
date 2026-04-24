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