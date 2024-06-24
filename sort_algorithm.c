/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:39:21 by mfrancis          #+#    #+#             */
/*   Updated: 2024/06/24 11:34:33 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_algorithm(t_data *data)
{
	int	average;

	while (data->a_size > 5)
	{
		average = find_average(data);
		if (data->a_head->value > average)
			ra_operation(data, 'a');
		else
			pb_operation(data, 'b');
	}
	sort_five(data);
	while (data->b_size > 0)
	{
		cheapest_cost(data);
		move_to_a(data);
	}
	rotate_to_min(data);
}

int	find_average(t_data *data)
{	
	if (!data || !data->a_head)
		return (-1);
	int		res;
	t_node	*temp;

	res = 0;
	temp = data->a_head;

	while (temp)
	{
		res += temp->value;
		temp = temp->next;
	}
	res /= data->a_size;
	return (res);
}

void	cheapest_cost(t_data *data)
{
	t_node	*temp_b;
	int		cost_min;
	int		cost;

	cost = 0;
	cost_min = INT_MAX;
	temp_b = data->b_head;
	while (temp_b)
	{
		data->b_friend = temp_b->value;
		find_bestfriend(data);
		cost = final_cost(data);
		if (cost_min > cost)
		{
			cost_min = cost;
			data->best_bestfriend = data->bestfriend;
			data->best_node = temp_b->value;
		}
		temp_b = temp_b->next;
	}
	data->best_cost = cost_min;
}

void	move_to_a(t_data *data)
{
	int	idx_bff;
	int	idx_best;

	idx_bff = find_index_a(data->best_bestfriend, data);
	idx_best = find_index_b(data->best_node, data);
	while (data->a_head->value != data->best_bestfriend
		&& data->b_head->value != data->best_node)
	{
		if (idx_best <= data->b_size / 2 && idx_best <= data->b_size / 2)
			rr_operation(data, 'c');
		else if (idx_best > data->b_size / 2 && idx_best > data->b_size / 2)
			reverse_rr_operation(data, 'c');
	}
	while (data->a_head->value != data->best_bestfriend)
	{
		if (idx_bff <= data->a_size / 2)
			ra_operation(data, 'a');
		else
			reverse_ra_operation(data, 'a');
	}
	while (data->b_head->value != data->best_node)
	{
		if (idx_best <= data->b_size / 2)
			rb_operation(data, 'b');
		else
			reverse_rb_operation(data, 'b');
	}
	pa_operation(data, 'a');
}

void	rotate_to_min(t_data *data)
{
	t_node	*temp_a;
	int		smallest;
	int		idx;

	idx = 0;
	temp_a = data->a_head;
	smallest = get_min_val(data);
	while (temp_a)
	{
		if (temp_a->value == smallest)
			break ;
		temp_a = temp_a->next;
		idx++;
	}
	if (idx <= data->a_size / 2)
		while (data->a_head->value != smallest)
			ra_operation(data, 'a');
	else if (idx > (data->a_size / 2))
		while (data->a_head->value != smallest)
			reverse_ra_operation(data, 'a');
}

/*
	[x] sort bigger than 5
		[x] Transfer nbr to stack B until only have 5 nbr in stack A
			[x] find average
			[x] nr > average -ra
			[x] nr < average - pb
		[] Until b != 0
			[] find de min cost to move
				.-[] Compare cost of move bff and BFF next
				|   [] Calculate de cost of move BBF <-----.
				'------>[x] Find the BFF of nbr of stack B--'
							[x] if (nrb > nrA)
								[x] if(bff > bff before)
									[x] swap


			[] move to the top - function that i already made ?
				- need improvement

			[] pa-operation;

		[] rotate until have de smallest val in the beguin
			[] Find the small number

*/