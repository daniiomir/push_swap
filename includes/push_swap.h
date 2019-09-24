/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:26:19 by swarner           #+#    #+#             */
/*   Updated: 2019/09/24 15:25:15 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"

typedef struct		s_tools
{
	int				*stack_a;
	int				*stack_b;
	size_t 			count_of_num;
	size_t			size_a;
	size_t 			size_b;
	size_t 			error;
	size_t 			debug;
	size_t 			is_visible;
}					t_tools;

void				ft_error(void);
int 				*create_stack(size_t size);
void				init_valies(t_tools *tools);
int					validation(t_tools *tools, char *arg);
size_t 				find_duplicates(t_tools *tools);
size_t				is_sorted(t_tools *tools);
void				handle_arg(char *arg, t_tools *tools, size_t *counter);
void 				len_for_stack(int argc, char **argv, t_tools *tools);
void 				algorithm(t_tools *tools);
void 				to_stack_b(t_tools *tools);
void 				sort(t_tools *tools);
void 				operation(void (*f)(t_tools *, int), t_tools *tools);


void	print_stacks_dbg(t_tools *tools, int *s1, int *s2);

void				print_stacks(t_tools *tools);

#endif
