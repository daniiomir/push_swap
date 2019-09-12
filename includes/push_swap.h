/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:26:19 by swarner           #+#    #+#             */
/*   Updated: 2019/09/11 19:17:35 by swarner          ###   ########.fr       */
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
}					t_tools;

void				ft_error(void);
void				init_valies(t_tools *tools);
int					validation(char *arg);
size_t 				find_duplicates(t_tools *tools);
void				handle_arg(char *arg, t_tools *tools, size_t *counter);
void 				len_for_stack(int argc, char **argv, t_tools *tools);


void				print_stacks(t_tools *tools);

#endif
