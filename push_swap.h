#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <libft/libft.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct s_node t_node;

typedef struct s_node {
	t_node *next;
	int	index;
	int data;
} t_node;

typedef struct s_stack {
	t_node *top;
	int		size;
} t_stack;

void update_size_index(t_stack *stack);

//operators
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void rra(t_stack *stack);
void rrb(t_stack *stack);
void rrr(t_stack *a, t_stack *b);


int main(int ac, char *av[]);

//init
t_stack *init(int ac, char *av[]);
t_stack *new_empty_stack(void);

void push_top(t_stack *stack, t_node *node);
void push_bot(t_stack *stack, t_node *node);
t_node *pop_top(t_stack *stack);
t_node *pop_bot(t_stack *stack);
void rb_base(t_stack *b, bool print);
void test_pa();
void print_stack(t_stack *stack);
#endif