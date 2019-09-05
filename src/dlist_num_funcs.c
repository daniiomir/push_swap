/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_num_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:59:31 by swarner           #+#    #+#             */
/*   Updated: 2019/09/04 21:59:26 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist_num		*ft_dlist_new_num(ssize_t num)
{
	t_dlist_num	*new;

	if (!(new = (t_dlist_num *)malloc(sizeof(t_dlist_num))))
		return (NULL);
	if (!num)
		new->content = 0;
	else
		new->content = num;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void			ft_addnode_dlist_num(t_dlist_num **list, ssize_t num)
{
    t_dlist_num	*new;

    new = (t_dlist_num *)malloc(sizeof(t_dlist_num));
    new->content = num;
    new->next = NULL;
    new->prev = NULL;
    ft_dlistadd_end_num(list, new);
}

void			ft_dlistadd_end_num(t_dlist_num **list, t_dlist_num *new)
{
    t_dlist_num *current;

    current = *list;
    while (current->next != NULL)
        current = current->next;
    current->next = new;
    new->prev = current;
}

void			ft_dlist_num_del_current(t_dlist_num **current)
{
	t_dlist_num *next;
	t_dlist_num *prev;

	next = (*current)->next;
	prev = (*current)->prev;
	if (prev != NULL)
		prev->next = (*current)->next;
	if (next != NULL)
		next->prev = (*current)->prev;
}

void			ft_dlisthead_num_del(t_dlist_num **head)
{
	t_dlist_num *temp;

	temp = *head;
	*head = temp->next;
	(*head)->prev = NULL;
	free(temp);
}

void	ft_free_dlist_num(t_dlist_num *list)
{
	free(list);
}