#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <libft/libft.h>
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


#endif