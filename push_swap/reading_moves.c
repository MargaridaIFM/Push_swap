/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:22:27 by mfrancis          #+#    #+#             */
/*   Updated: 2024/06/25 21:10:29 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reading_moves(t_data *data)
{
	char	*operation;

	while (1)
	{
		operation = get_next_line(0);
		if (operation == NULL)
			break ;
		else
			execute_moves(data, operation);
		free(operation);
	}
}

void	execute_moves(t_data *data, char *operation)
{
	if (ft_strncmp(operation, "sa\n", 4) == 0)
		sa_operation(data, 'a');
	else if (ft_strncmp(operation, "pa\n", 4) == 0)
		pa_operation(data, 'a');
	else if (ft_strncmp(operation, "ra\n", 4) == 0)
		ra_operation(data, 'a');
	else if (ft_strncmp(operation, "rra\n", 5) == 0)
		reverse_ra_operation(data, 'a');
	else if (ft_strncmp(operation, "sb\n", 4) == 0)
		sb_operation(data, 'b');
	else if (ft_strncmp(operation, "pb\n", 4) == 0)
		pb_operation(data, 'b');
	else if (ft_strncmp(operation, "rb\n", 4) == 0)
		rb_operation(data, 'b');
	else if (ft_strncmp(operation, "rrb\n", 5) == 0)
		reverse_rb_operation(data, 'b');
	else if (ft_strncmp(operation, "rr\n", 4) == 0)
		rr_operation(data, 'c');
	else if (ft_strncmp(operation, "rrr\n", 5) == 0)
		reverse_rr_operation(data, 'c');
	else
		free_exit(data, "Error\n");
}

void	free_exit_checker(t_data *data, char *str)
{
	if (str)
		ft_putstr_fd(str, 1);
	if (data->a_head)
		free_node(data->a_head);
	if (data->b_head)
		free_node(data->b_head);
	exit(0);
}
