/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:18:52 by mfrancis          #+#    #+#             */
/*   Updated: 2024/06/23 21:32:38 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_operation(t_data *data, char c)
{
	t_node	*temp;

	if (!(data) || !(data)->a_head || !(data)->a_head->next)
		return ;
	temp = data->a_head;
	data->a_head = data->a_head->next;
	data->a_head->prev = NULL;
	data->a_tail->next = temp;
	temp->prev = data->a_tail;
	temp->next = NULL;
	data->a_tail = temp;
	if (c == 'a')
		ft_printf("ra\n");
}

void	rb_operation(t_data *data, char c)
{
	t_node	*temp;

	if (!(data) || !(data)->b_head || !(data)->b_head->next)
		return ;
	temp = data->b_head;
	data->b_head = data->b_head->next;
	data->b_head->prev = NULL;
	data->b_tail->next = temp;
	temp->prev = data->b_tail;
	temp->next = NULL;
	data->b_tail = temp;
	if (c == 'b')
		ft_printf("rb\n");
}

void	rr_operation(t_data *data, char c)
{
	ra_operation(data, c);
	rb_operation(data, c);
	ft_printf("rr\n");
}
