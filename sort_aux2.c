/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algoritm_aux2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:43:07 by mfrancis          #+#    #+#             */
/*   Updated: 2024/06/23 17:44:17 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_from_tail_b(t_data *data)
{
	t_node	*temp_b;
	int		counter;

	counter = 0;
	temp_b = data->b_tail;
	while (temp_b && temp_b->value != data->b_friend)
	{
		counter++;
		temp_b = temp_b->prev;
	}
	return (counter + 1);
}
int find_index_a(int value, t_data *data)
{
    int i;
    t_node  *temp;
    
    i = 0;
    temp = data->a_head;
    while(temp)
    {
        if(temp->value == value)
            return(i);
        i++;
        temp= temp->next;
    }
    return(-1);
}

int find_index_b(int value, t_data *data)
{
    int i;
    t_node  *temp;
    
    i = 0;
    temp = data->b_head;
    while(temp)
    {
		
        if(temp->value == value)
            return(i);
        i++;
        temp= temp->next;
    }
    return(ft_printf("Deu ......\n"), -1);
}