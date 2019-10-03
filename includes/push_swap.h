/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:26:19 by swarner           #+#    #+#             */
/*   Updated: 2019/10/03 21:13:47 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"

typedef struct		s_tools
{
	int				*stack_a;
	int				*stack_b;
	size_t			count_of_num;
	size_t			size_a;
	size_t			size_b;
	size_t			error;
	size_t			debug;
	size_t			color;
	size_t			is_visible;
	size_t			op_count;
}					t_tools;

typedef struct		s_moves
{
	int				elem;
	int				a_moves;
	char			*a_rot_type;
	char			*b_rot_type;
	char			*common_rot;
	int				b_moves;
	int				common_moves;
	int				total;
}					t_moves;

void				ft_error(void);
int					*create_stack(size_t size);
void				init_valies(t_tools *tools);
int					parse_options(char *param1, char *param2, t_tools *tools);
int					validation(t_tools *tools, char *arg);
size_t				find_duplicates(t_tools *tools);
size_t				is_sorted(t_tools *tools);
void				handle_arg(char *arg, t_tools *tools, size_t *counter);
void				len_for_stack(int argc, char **argv, t_tools *tools);
void				algorithm(t_tools *tools);
void				global_sort(t_tools *tools);
int					find_place_in_a(int *stack, int len, int elem,
	char **rot_type);
void				operation(void (*f)(t_tools *, int), t_tools *tools);
t_moves				*best_way_from_a_to_b(t_tools *tools);
void				place_smallest_first_a(t_tools *tools);
int					find_max_elem(const int *stack, int stack_len);
int					find_min_elem(const int *stack, int stack_len);
int					find_max_index(const int *stack, int len);
int					find_min_index(const int *stack, int len);
int					find_a_rot_type(int len, int pos, char **a_rot_type);
int					find_b_rot_type(int len, int pos, char **b_rot_type);
void				free_moves(t_moves *moves);
void				free_stacks(t_tools *tools);
void				print_stacks(t_tools *tools);
void				print_stacks_color(t_tools *tools);

#endif
