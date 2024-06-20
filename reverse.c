/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:18:59 by mfrancis          #+#    #+#             */
/*   Updated: 2024/06/12 08:26:10 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_ra_operation(t_data *data, char c)
{
	t_node	*temp;

	if (!(data) || !(data)->a_head || !(data)->a_head->next)
		return ;
	temp = data->a_tail;
	data->a_tail = data->a_tail->prev;
	data->a_tail->next = NULL;
	temp->prev = NULL;
	temp->next = data->a_head;
	data->a_head->prev = temp;
	data->a_head = temp;
	if (c == 'a')
		ft_printf("rra\n");
}

void	reverse_rb_operation(t_data *data, char c)
{
	t_node	*temp;

	if (!(data) || !(data)->b_head || !(data)->b_head->next)
		return ;
	temp = data->b_tail;
	data->b_tail = data->b_tail->prev;
	data->b_tail->next = NULL;
	temp->prev = NULL;
	temp->next = data->b_head;
	data->b_head->prev = temp;
	data->b_head = temp;
	if (c == 'b')
		ft_printf("rrb\n");
}
void	reverse_rr_operation(t_data *data, char c)
{
	reverse_ra_operation(data, c);
	reverse_rb_operation(data, c);
	ft_printf("rrr\n");
}