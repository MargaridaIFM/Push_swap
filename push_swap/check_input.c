/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:09:42 by mfrancis          #+#    #+#             */
/*   Updated: 2024/06/24 14:48:39 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input(char *argv, t_data *data)
{
	char	*str;
	int		sign;

	str = argv;
	sign = 0;
	if (!*str)
		free_exit(data, "Error\n");
	if (str[0] == '-' || str[0] == '+')
	{
		if (!str[1])
			free_exit(data, "Error\n");
		if (str[0] == '-')
			sign = -1;
		str++;
	}
	if (ft_strlen(str) >= 10)
		if (limit_value(str, sign) == 0)
			free_exit(data, "Error\n");
	while (*str)
	{
		if (!ft_isdigit(*str))
			free_exit(data, "Error\n");
		str++;
	}
}

int	limit_value(char *str, int sign)
{
	if (sign == -1)
	{
		if (ft_strncmp(str, "2147483648", 12) <= 0 && ft_strlen(str) == 10)
			return (1);
	}
	else
	{
		if (ft_strncmp(str, "2147483647", 12) <= 0 && ft_strlen(str) == 10)
			return (1);
	}
	return (0);
}

void	check_doubles(t_data *data)
{
	t_node	*temp1;
	t_node	*temp2;

	temp1 = data->a_head;
	while (temp1 && temp1->next)
	{
		temp2 = temp1->next;
		while (temp2)
		{
			if (temp1->value == temp2->value)
				free_exit(data, "Error\n");
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}
