/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:38:11 by mfrancis          #+#    #+#             */
/*   Updated: 2024/06/23 22:07:35 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_bestfriend(t_data *data)
{
	t_node	*temp_a;
	int		bestfriend;

	bestfriend = INT_MAX;
	temp_a = data->a_head;
	while (temp_a)
	{
		if (data->b_friend < temp_a->value && bestfriend > temp_a->value)
			bestfriend = temp_a->value;
		temp_a = temp_a->next;
	}
	if (bestfriend == INT_MAX)
		bestfriend = get_min_val(data);
	data->bestfriend = bestfriend;
}

int	final_cost(t_data *data)
{
	int	final_cost;
	int	cost_a;
	int	cost_b;

	cost_a = 0;
	cost_b = 0;
	if (calc_from_head_a(data) <= calc_from_tail_a(data))
		cost_a = calc_from_head_a(data);
	else
		cost_a = calc_from_tail_a(data);
	if (calc_from_head_b(data) <= calc_from_tail_b(data))
		cost_b = calc_from_head_b(data);
	else
		cost_b = calc_from_tail_b(data);
	final_cost = cost_a + cost_b;
	return (final_cost);
}

int	calc_from_head_a(t_data *data)
{
	t_node	*temp_a;
	int		counter;

	counter = 0;
	temp_a = data->a_head;
	while (temp_a && temp_a->value != data->bestfriend)
	{
		counter++;
		temp_a = temp_a->next;
	}
	return (counter);
}

int	calc_from_tail_a(t_data *data)
{
	t_node	*temp_a;
	int		counter;

	counter = 0;
	temp_a = data->a_tail;
	while (temp_a && temp_a->value != data->bestfriend)
	{
		temp_a = temp_a->prev;
		counter++;
	}
	return (counter + 1);
}

int	calc_from_head_b(t_data *data)
{
	t_node	*temp_b;
	int		counter;

	counter = 0;
	temp_b = data->b_head;
	while (temp_b && temp_b->value != data->b_friend)
	{
		counter++;
		temp_b = temp_b->next;
	}
	return (counter);
}
