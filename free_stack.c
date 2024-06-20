/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:00:49 by mfrancis          #+#    #+#             */
/*   Updated: 2024/06/13 09:09:13 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_data_node(t_node **head)
{
    t_node *current = *head;
    t_node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;  // Para evitar dangling pointers
}

void free_data(t_data *data)
 {
    if (data == NULL)
        return;
    free_data_node(&(data->a_head));
    free_data_node(&(data->b_head));
    
    data->a_tail = NULL;
    data->b_tail = NULL;
    data->a_size = 0;
    data->b_size = 0;
}

void free_stack(t_data *data, char *message) 
{
    free_data(data);
    printf("%s\n", message);
    exit(0);
}