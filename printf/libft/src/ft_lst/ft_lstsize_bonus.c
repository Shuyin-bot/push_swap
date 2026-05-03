/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 02:44:35 by sqian             #+#    #+#             */
/*   Updated: 2025/11/12 03:30:48 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	n;

	n = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		n++;
	}
	return (n);
}

// int	main()
// {
// 	// create nodes
//     t_list *nodes[5];                 // 4 nodes + NULL sentinel
//     nodes[0] = ft_lstnew("test1");
//     nodes[1] = ft_lstnew("test2");
//     nodes[2] = ft_lstnew("test3");
//     nodes[3] = ft_lstnew("test4");
//     nodes[4] = NULL;

//     // link them into a list
//     for (int i = 0; nodes[i] && nodes[i + 1]; i++)
//         nodes[i]->next = nodes[i + 1];

//     t_list *head = nodes[0];

//     // use your function
//     int n = ft_lstsize(head);
//     printf("size = %d\n", n);

//     // optional: show contents
//     for (t_list *p = head; p; p = p->next)
//         printf("%s ", (char *)p->content);
//     printf("\n");

//     // free only the nodes (string literals are not freed)
//     for (t_list *p = head; p; ) {
//         t_list *next = p->next;
//         free(p);
//         p = next;
// 	}

// }
