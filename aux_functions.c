/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 08:11:46 by mfrancis          #+#    #+#             */
/*   Updated: 2024/06/18 17:49:12 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void null_initialization_s_data(t_data *data)
{
    data->a_head = NULL;
    data->b_head = NULL;
    data->a_tail = NULL;
    data->b_tail = NULL;
    data->b_size = 0;
    data->a_size = 0;
    data->best_cost = 0;
    data->bestfriend = 0;
    data->b_friend = 0;
    data->best_bestfriend = 0;
    data->best_node = 0;
}

void free_exit(t_data *data, char *str)
{
    if(str && str[0] != '\0')
        ft_putstr_fd(str, 2);
    if(data->a_head)
        free_node(data->a_head);
    if(data->b_head)
        free_node(data->b_head);
    exit(0);    
}
void free_node(t_node *node)
{
    t_node *temp;
   
    while (node) 
    {
        temp = node->next;
        free(node);
        node = temp;
    }
}