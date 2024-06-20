/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:54:07 by mfrancis          #+#    #+#             */
/*   Updated: 2024/06/14 06:01:35 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Delete element from the list and free the allocated memory of that node.
 Return Value None. */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->value);
	free(lst);
}
/*void delete_lst(void *value)
{
	free(value);
}
int main(void)
{
	t_list *head = NULL;
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	node1->value = "Hello";
	node2->value = "Darling";
	node3->value = "END";

	head = node3;
	node3->next = node2;
	node2->next = node1;
	node1->next = NULL;

	printf("Before free: %s\n", (char *)node2->value);
	ft_lstdelone(node1, &delete_lst);
	printf("Nodes: %s\n %s\n", (char *)node1->value, (char *)node3->value);
	free(node1->value);
    free(node1);
    free(node3->value);
    free(node3);
} */