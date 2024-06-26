/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:05:09 by mfrancis          #+#    #+#             */
/*   Updated: 2024/06/26 15:35:56 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_operation(t_data *data, char c)
{
	t_node	*temp_a;

	if (!(data) && !(data->a_head) && !(data->a_head->next))
		return ;
	temp_a = data->a_head;
	data->a_head = temp_a->next;
	temp_a->next = data->a_head->next;
	data->a_head->prev = NULL;
	if (temp_a->next)
		temp_a->next->prev = temp_a;
	data->a_head->next = temp_a;
	temp_a->prev = data->a_head;
	if (c == 'a')
		ft_printf("sa\n");
}

void	sb_operation(t_data *data, char c)
{
	t_node	*temp_b;

	if (!(data) && !(data->b_head) && !(data->b_head->next))
		return ;
	temp_b = data->b_head;
	data->b_head = temp_b->next;
	temp_b->next = data->b_head->next;
	data->b_head->prev = NULL;
	if (temp_b->next)
		temp_b->next->prev = temp_b;
	data->b_head->next = temp_b;
	temp_b->prev = data->b_head;
	if (c == 'b')
		ft_printf("sb\n");
}

void	ss_operation(t_data *data, char c)
{
	sa_operation(data, c);
	sb_operation(data, c);
	ft_printf("ss\n");
}
