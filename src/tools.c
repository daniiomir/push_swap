/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:41:09 by swarner           #+#    #+#             */
/*   Updated: 2019/09/05 18:17:42 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
}

int		validation(char *arg)
{
	ssize_t	num;

	num = ft_atoi(arg);
	if (num > 2147483647 || num < -2147483648)
		ft_error();
	if (num + '0' != arg[0] && num == 0)
		ft_error();
	return (num);
}

size_t 	find_duplicates(t_dlist_num **stack_a)
{
	size_t 		count;
	size_t 		is_dup;
	t_dlist_num *current;
	t_dlist_num *current2;

	current = *stack_a;
	while (current != NULL)
	{
		current2 = *stack_a;
		count = 0;
		is_dup = 0;
		while (current2 != NULL)
		{
			if (current->content == current2->content && !count && !is_dup)
			{
				if (current2->next != NULL)
					current2 = current2->next;
				else
					break ;
				count++;
			}
			if (current->content == current2->content)
				return (1);
			if (!count)
				current2 = current2->next;
			else
			{
				count--;
				is_dup++;
			}
		}
		if (current->next != NULL)
			current = current->next;
	}
	return (0);
}

void 	len_for_stack(int argc, char **argv, t_tools *tools)
{
	int 	i;
	size_t 	len;

	i = 1;
	while (argc > i)
	{
		len = ft_count_words(argv[i], ' ');
		tools->count_of_num = len;
		tools->size_a = len;
		tools->size_b = 0;
		i++;
	}
}

void	handle_arg(char *arg, t_dlist_num **stack_a)
{
	int 	num;
	size_t 	j;
	size_t 	args_count;
	char 	**few_args;

	args_count = ft_count_words(arg, ' ');
	if (args_count == 1)
	{
		num = validation(arg);
		ft_addnode_dlist_num(stack_a, num);
		ft_putnbr(num);
	}
	else
	{
		few_args = ft_strsplit(arg, ' ');
		j = 0;
		while (j < args_count)
		{
			num = validation(few_args[j]);
            ft_addnode_dlist_num(stack_a, num);
			free(few_args[j++]);
			ft_putnbr(num);
		}
		free(few_args);
	}
}