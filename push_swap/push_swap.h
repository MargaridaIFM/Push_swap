/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:27:13 by mfrancis          #+#    #+#             */
/*   Updated: 2024/06/24 14:49:21 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_data
{
	t_node			*a_head;
	t_node			*b_head;
	t_node			*a_tail;
	t_node			*b_tail;
	int				a_size;
	int				b_size;
	int				best_cost;
	int				bestfriend;
	int				b_friend;
	int				best_bestfriend;
	int				best_node;
}					t_data;

// Auxiliar funcitons
void				null_initialization_s_data(t_data *data);
void				free_exit(t_data *data, char *str);
void				free_node(t_node *node);

// Parsing - Organize
void				ft_parsing(char *argv[], t_data *data);

// Check input
void				check_input(char *argv, t_data *data);
int					limit_value(char *str, int sign);
void				check_doubles(t_data *data);

// Add Arguments
void				add_arg_a(int nb, t_data *data);
void				add_to_tail_a(t_data *data, t_node *new);

// operations
void				sa_operation(t_data *data, char c);
void				sb_operation(t_data *data, char c);
void				ss_operation(t_data *data, char c);
void				ra_operation(t_data *data, char c);
void				rb_operation(t_data *data, char c);
void				rr_operation(t_data *data, char c);
void				reverse_ra_operation(t_data *data, char c);
void				reverse_rb_operation(t_data *data, char c);
void				reverse_rr_operation(t_data *data, char c);
void				pa_operation(t_data *data, char c);
void				pb_operation(t_data *data, char c);

// sorting
int					check_is_sorted(t_data *data);
void				sorting(t_data *data, int a_size);
void				sort_two(t_data *data);
void				sort_three(t_data *data);
void				sort_four(t_data *data);
//------------------------ sort 5 --------------------------//
void				sort_five(t_data *data);
int					get_index(int max_val, t_data *data);
int					get_max_val(t_data *data);
int					get_min_val(t_data *data);
void				put_top_a(t_data *data, int index_val);
//-------------------- sort algorithm ---------------------//
void				sort_algorithm(t_data *data);
int					find_average(t_data *data);
void				cheapest_cost(t_data *data);
void				move_to_a(t_data *data);
void				rotate_to_min(t_data *data);
//---------------------- sort aux 1 ----------------------//
void				find_bestfriend(t_data *data);
int					final_cost(t_data *data);
int					calc_from_head_a(t_data *data);
int					calc_from_tail_a(t_data *data);
int					calc_from_head_b(t_data *data);
//---------------------- sort  aux 2 ----------------------//
int					calc_from_tail_b(t_data *data);
int					find_index_a(int value, t_data *data);
int					find_index_b(int value, t_data *data);
void				move_to_a_aux(t_data *data, int idx_best);

// Test Print functions - put on the libft at the end
void				print_data_a_front(t_data *data);
void				print_data_b_front(t_data *data);
void				print_data_a_back(t_data *data);
void				print_data_b_back(t_data *data);

#endif