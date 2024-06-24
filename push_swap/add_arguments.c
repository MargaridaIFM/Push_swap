/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_arg_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:54:57 by mfrancis          #+#    #+#             */
/*   Updated: 2024/06/10 17:00:34 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_arg_a(int nb, t_data *data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = nb;
	new_node->next = NULL;
	add_to_tail_a(data, new_node);
}

void	add_to_tail_a(t_data *data, t_node *new)
{
	if (!data || !new)
		return ;
	if (!data->a_tail)
	{
		data->a_tail = new;
		data->a_head = new;
	}
	else if (data->a_tail)
	{
		data->a_tail->next = new;
		new->prev = data->a_tail;
		data->a_tail = new;
	}
}
