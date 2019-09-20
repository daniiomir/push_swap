/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:26:19 by swarner           #+#    #+#             */
/*   Updated: 2019/09/12 18:00:26 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H

# define OPERATIONS_H

# include "libft.h"
# include "push_swap.h"

void	sa(t_tools *tools, int is_visible);
void	sb(t_tools *tools, int is_visible);
void	ss(t_tools *tools, int is_visible);

void	pa(t_tools *tools, int is_visible);
void	pb(t_tools *tools, int is_visible);

void	ra(t_tools *tools, int is_visible);
void	rb(t_tools *tools, int is_visible);
void	rr(t_tools *tools, int is_visible);

void	rra(t_tools *tools, int is_visible);
void	rrb(t_tools *tools, int is_visible);
void	rrr(t_tools *tools, int is_visible);

#endif
