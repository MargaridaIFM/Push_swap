/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:59:46 by mfrancis          #+#    #+#             */
/*   Updated: 2024/06/24 11:18:49 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**@brief
 pa (push a): Takes the first element on top of b and puts it on a.
 Does nothing if b is empty.

@param t_lis
*/
void	pa_operation(t_data *data, char c)
{
	t_node	*temp;

	if (!(data) || !(data)->b_head || data->b_size == 0)
		return ;
	temp = data->b_head;
	data->b_head = data->b_head->next;
	if (data->b_head)
		data->b_head->prev = NULL;
	else
		data->b_tail = NULL;
	if (data->a_head)
		data->a_head->prev = temp;
	else
		data->a_tail = temp;
	temp->next = data->a_head;
	data->a_head = temp;
	data->a_size++;
	data->b_size--;
	if (c == 'a')
		ft_printf("pa\n");
}

/**@brief
 pb (push b): Takes the first element on top of a and puts it on b.
 Does nothing if a is empty.

@param t_lis
*/
void	pb_operation(t_data *data, char c)
{
	t_node	*temp;

	if (!(data) || !(data)->a_head || data->a_size == 0)
		return ;
	temp = data->a_head;
	data->a_head = data->a_head->next;
	if (data->a_head)
		data->a_head->prev = NULL;
	else
		data->a_tail = NULL;
	if (data->b_head)
		data->b_head->prev = temp;
	else
		data->b_tail = temp;
	temp->next = data->b_head;
	data->b_head = temp;
	data->b_size++;
	data->a_size--;
	if (c == 'b')
		ft_printf("pb\n");
}
/*
	.------------.
	A - (NULL) 5 3 4 7 6 2 (NULL)
	.----------'
	B - (NULL) 1 [...]
	temp = 1


			.---------.
	A - (NULL) (5)-x-3 4 7 6 2 (NULL)

	B - (NULL) 5 [...] (NULL)
	temp = 1 <-'


	A - (NULL) 3 4 7 6 2 (NULL)

	B - (NULL) 5 1 [...] (NULL)
	temp = 1---^
*/
/*void pb_operation(t_data *data, char c)
{
	t_node *temp;
	// considerar um int para o size
	if (!(data) || !(data)->a_head)
		return ;
	temp= data->a_head;
	data->a_head = data->a_head->next;
	if (data->a_head)
		data->a_head->prev = NULL;
	else
		data->a_tail = NULL;
	if(data->b_head)
		data->b_head->prev = temp;
	else
		data->b_tail= temp;
	temp->next = data->b_head;\
	temp->prev = NULL;
	data->b_head = temp;

	data->b_size++;
	data->a_size--;

	if (c == 'b')
		ft_printf("pb\n");
}*/
/*void pa_operation(t_data *data, char c)
{
	t_node *temp;
	// considerar um int para o size
	if (!(data) && !(data)->b_head)
		return ;
	temp= data->b_head;
	data->b_head = data->b_head->next;
	if (data->b_head)
		data->b_head->prev = NULL;
	else
		data->b_tail = NULL;
	if(data->a_head)
		data->a_head->prev = temp;
	else
		data->a_tail= temp;
	temp->next = data->a_head;\
	temp->prev = NULL;
	data->a_head = temp;

	data->a_size++;
	data->b_size--;

	if (c == 'a')
		ft_printf("pa\n");
}*/