/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:26:19 by swarner           #+#    #+#             */
/*   Updated: 2019/09/04 21:59:11 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"

typedef struct		s_double_linked_list_num
{
    ssize_t						    content;
    struct s_double_linked_list_num	*next;
    struct s_double_linked_list_num	*prev;
}					t_dlist_num;

typedef struct		s_tools
{
	size_t 			count_of_num;
	size_t			size_a;
	size_t 			size_b;
}					t_tools;

void				ft_error(void);
int					validation(char *arg);
size_t 				find_duplicates(t_dlist_num **stack_a);
void				handle_arg(char *arg, t_dlist_num **stack_a);
void 				len_for_stack(int argc, char **argv, t_tools *tools);

/*
 *  LIST FUNCS
 * */

t_dlist_num			*ft_dlist_new_num(ssize_t num);
void	            ft_addnode_dlist_num(t_dlist_num **list, ssize_t num);
void				ft_dlistadd_end_num(t_dlist_num **list, t_dlist_num *new);
void				ft_dlist_num_del_current(t_dlist_num **current);
void				ft_dlisthead_num_del(t_dlist_num **head);
void				ft_free_dlist_num(t_dlist_num *list);


#endif
