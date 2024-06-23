/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:32:22 by mfrancis          #+#    #+#             */
/*   Updated: 2024/06/23 17:29:13 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// ver funcao find_index e manter so a outra, esta e usado no sort five;

void	sort_five(t_data *data)
{
    int idx_val_max;
    int idx_val_min;
    
    idx_val_max = get_index(get_max_val(data), data);
    put_top_a(data, idx_val_max);
    pb_operation(data,'b');
    idx_val_min = get_index(get_min_val(data), data);
    put_top_a(data, idx_val_min);
    pb_operation(data,'b');
    sort_three(data);
    pa_operation(data,'a');
    pa_operation(data,'a');
    ra_operation(data, 'a');
}
int get_index(int max_val, t_data *data)
{
    int i;
    t_node  *temp;
    
    i = 0;
    temp = data->a_head;
    while(temp)
    {
        if(temp->value == max_val)
            return(i);
        i++;
        temp= temp->next;
    }
    return(ft_printf("Deu ......\n"), -1);
}
int get_max_val(t_data *data)
{
    int max_val;
    t_node *temp;
    
    if(!data)
        return (-1);

    temp = data->a_head;
    max_val = temp->value;
    while (temp)
    {
        if(temp->value > max_val)
            max_val = temp->value;
       temp = temp->next;
    }
    return(max_val); 
}
int get_min_val(t_data *data)
{

    int min_val;
    t_node *temp;
    
    if((!data))
        return (-1);
        
    temp = data->a_head;
    min_val = temp->value;
    while (temp)
    {
        if(temp->value < min_val)
            min_val = temp->value;
       temp = temp->next;
    }
    return(min_val); 
}
void put_top_a(t_data *data, int index_val)
{
    if(index_val <= (data->a_size / 2))
    {
        while(index_val > 0)
        {
            ra_operation(data, 'a');
            index_val--;
        }
    }
    else
    {
        while(index_val < (data->a_size -1))
        {
            reverse_ra_operation(data, 'a');
            index_val++;
        }
        reverse_ra_operation(data, 'a');
    }
    
}