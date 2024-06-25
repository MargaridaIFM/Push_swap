/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:34:21 by mfrancis          #+#    #+#             */
/*   Updated: 2024/06/25 21:10:15 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2 || (argc > 2 && argv[1][0] == '\0'))
		return (0);
	null_initialization_s_data(&data);
	ft_parsing(argv, &data);
	data.a_size = argc - 1;
	if (check_is_sorted(&data) == 0)
		free_exit_checker(&data, "OK\n");
	reading_moves(&data);
	if (check_is_sorted(&data) == 0 && data.b_head == NULL)
		free_exit_checker(&data, "OK\n");
	else
		free_exit_checker(&data, "KO\n");
	return (0);
}
