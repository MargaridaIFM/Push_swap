/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:53:14 by mfrancis          #+#    #+#             */
/*   Updated: 2024/06/16 10:49:58 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parsing(char *argv[], t_data *data)
{
    int i;
    i = 0;
    while(argv[++i])
    { 
		check_input(argv[i], data);
		add_arg_a(atoi(argv[i]), data);
	}
	check_doubles(data);
}

/*	
		PARSING:
			[X] check int min and max
			[X] check invalid chars
			[x] check doubles

		ADD ELEMENTS TO THE LIST
			[x] create node
			[x] 		- put value in the node
			[x]			- link prev;
			[x]			- link next;
			[x] append the node to the list
		
		IMPORTANTE FUNCTIONS:
			[x] free_exit

*/