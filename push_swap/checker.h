/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:34:57 by mfrancis          #+#    #+#             */
/*   Updated: 2024/06/26 14:03:20 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft/libft.h"
# include "push_swap.h"

int		main(int argc, char **argv);
void	free_exit_checker(t_data *data, char *str);
void	reading_moves(t_data *data);
void	execute_moves(t_data *data, char *operation);

#endif