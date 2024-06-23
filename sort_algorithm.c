/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:39:21 by mfrancis          #+#    #+#             */
/*   Updated: 2024/06/20 22:41:24 by mfrancis         ###   ########.fr       */
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
		print_data_a_front(data);
		print_data_b_front(data);
		cheapest_cost(data);
		//ft_printf("Final best: %d\n", data->best_node);
		//ft_printf("Final Bff: %d\n", data->best_bestfriend);
		ft_printf("Chepeast cost: %d\n", data->best_cost);
		move_to_a(data);
	}
	rotate_to_min(data);
}

int	find_average(t_data *data)
{
	int		res;
	t_node	*temp;

	res = 0;
	temp = data->a_head;
	if (!data || !data->a_head)
		return (-1);
	while (temp)
	{
		res += temp->value;
		temp = temp->next;
	}
	res /= data->a_size;
	return (res);
}
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
	int	cost_head_a;
	int	cost_tail_a;
	int	cost_head_b;
	int	cost_tail_b;

	cost_head_a = calc_from_head_a(data);
	cost_tail_a = calc_from_tail_a(data) - 1;
	cost_head_b = calc_from_head_b(data);
	cost_tail_b = calc_from_tail_b(data) - 1 ;
	
	ft_printf("Final best: %d\n", data->best_node);
	ft_printf("Final Bff: %d\n", data->best_bestfriend);
	ft_printf("Head A:%d\n", cost_head_a);
	ft_printf("Tail A:%d\n", cost_tail_a);
	ft_printf("Head B:%d\n", cost_head_b);
	ft_printf("Tail B:%d\n", cost_tail_b);
	
pa_operation(data, 'a');}
// if (calc_from_head_a(data) <= calc_from_tail_a(data)
// 	&& calc_from_head_b(data) <= calc_from_tail_b(data))
// {
// 	while (calc_from_head_a(data) > 0
// 		&& calc_from_head_b(data) > 0)
// 		rr_operation(data, 'c');
// }
// else if (calc_from_tail_a(data) < calc_from_head_a(data)
// 	&& calc_from_tail_b(data) < calc_from_head_b(data))
// {
// 	while (calc_from_tail_a(data) > 0
// 		&& calc_from_tail_b(data) > 0)
// 		reverse_rr_operation(data, 'c');
// }
// 	if (calc_from_head_a(data) <= calc_from_tail_a(data))
// 	{
// 		while (data->a_head->value != data->best_bestfriend)
// 			ra_operation(data, 'a');
// 	}
// 	else if (calc_from_head_a(data) > calc_from_tail_a(data))
// 	{
// 		while (data->a_head->value != data->best_bestfriend)
// 			reverse_ra_operation(data, 'a');
// 	}
// 	if (calc_from_head_b(data) < calc_from_tail_b(data))
// 	{
// 		while (data->b_head->value != data->best_node)
// 			rb_operation(data, 'b');
// 	}
// 	else if (calc_from_head_b(data) >= calc_from_tail_b(data))
// 	{
// 		while (data->b_head->value != data->best_node)
// 			reverse_rb_operation(data, 'b');
// 	}
// 	pa_operation(data, 'a');
//
int	final_cost(t_data *data)
{
	int	final_cost;
	int	cost_a;
	int	cost_b;

	cost_a = 0;
	cost_b = 0;
	if (calc_from_head_a(data) <= calc_from_tail_a(data))
	{
		cost_a = calc_from_head_a(data);
		// ft_printf("Head A: %d\n", cost_a);
	}
	else
	{
		cost_a = calc_from_tail_a(data);
		// ft_printf("Tail A: %d\n", cost_a);
	}
	if (calc_from_head_b(data) <= calc_from_tail_b(data))
	{
		cost_b = calc_from_head_b(data);
		// ft_printf("Head B: %d\n", cost_b);
	}
	else
	{
		cost_b = calc_from_tail_b(data);
		// ft_printf("Tail B: %d\n", cost_b);
	}
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
void	rotate_to_min(t_data *data)
{
	t_node	*temp_a;
	int		smallest;
	int		idx;

	ft_printf("Entrou no rotate to min\n");
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