/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:39:17 by mfrancis          #+#    #+#             */
/*   Updated: 2024/06/23 17:25:42 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_sorted(t_data *data)
{
	t_node	*current;

	current = data->a_head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (1);
		current = current->next;
	}
	return (0);
}
void	sorting(t_data *data, int a_size)
{
	if (a_size == 2)
		sort_two(data);
	else if (a_size == 3)
		sort_three(data);
	else if (a_size == 4)
	   sort_four(data);
	else if (a_size == 5)
	    sort_five(data);
	else
	   sort_algorithm(data);
}
void	sort_two(t_data *data)
{
	t_node	*temp;

	temp = data->a_head;
	if (temp->value > temp->next->value)
		sa_operation(data, 'a');
}
void	sort_three(t_data *data)
{

	if (data->a_head->value < data->a_head->next->value)
	{
        if(data->a_head->value > data->a_head->next->next->value)
            reverse_ra_operation(data, 'a'); 
        else if(data->a_head->next->value > data->a_head->next->next->value)
        {
            reverse_ra_operation(data, 'a');
            sa_operation(data, 'a');
        }
	}
    else if(data->a_head->value > data->a_head->next->value)
    {
        if(data->a_head->next->value > data->a_head->next->next->value)
        {
            ra_operation(data, 'a');
            sa_operation(data, 'a');
        }
        else if (data->a_head->value > data->a_head->next->next->value)
            ra_operation(data, 'a');
        else if (data->a_head->value < data->a_head->next->next->value)
            sa_operation(data, 'a');
    }
}
void sort_four(t_data *data)
{
    int idx_val_min;

    idx_val_min = get_index(get_min_val(data), data);
    put_top_a(data, idx_val_min);
    pb_operation(data,'b');
    sort_three(data);
    pa_operation(data,'a');
}