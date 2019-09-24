/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:41:09 by swarner           #+#    #+#             */
/*   Updated: 2019/09/24 15:02:00 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_error(void)
{
	write(1, "Error\n", 6);
}

void	init_valies(t_tools *tools)
{
	tools->count_of_num = 0;
	tools->size_a = 0;
	tools->size_b = 0;
	tools->error = 0;
	tools->debug = 0;
	tools->is_visible = 0;
}

int		validation(t_tools *tools, char *arg)
{
	ssize_t	num;

	num = ft_atoi(arg);
	if (num > 2147483647 || num < -2147483648 || num == -1)
		tools->error = 1;
	if (num + '0' != arg[0] && num == 0)
		tools->error = 1;
	return (num);
}

size_t 	find_duplicates(t_tools *tools)
{
	size_t			i;
	size_t			j;
	size_t			count;
	size_t			is_dup;

	i = 0;
	while (i < tools->count_of_num - 1)
	{
		j = 0;
		count = 0;
		is_dup = 0;
		while (j < tools->count_of_num)
		{
			if (tools->stack_a[i] == tools->stack_a[j] && !count && !is_dup)
			{
				if (j < tools->count_of_num)
					j++;
				else
					break ;
				count++;
			}
			if (tools->stack_a[i] == tools->stack_a[j])
				return (1);
			if (!count)
				j++;
			else
			{
				count--;
				is_dup++;
			}
		}
		if (i < tools->count_of_num)
			i++;
		else
			break ;
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
		tools->count_of_num += len;
		tools->size_a += len;
		i++;
	}
}

void	handle_arg(char *arg, t_tools *tools, size_t *counter)
{
	int 	num;
	size_t 	i;
	size_t 	j;
	size_t 	args_count;
	char 	**few_args;

	i = *counter;
	args_count = ft_count_words(arg, ' ');
	if (args_count == 1)
	{
		num = validation(tools, arg);
		tools->stack_a[i++] = num;
	}
	else
	{
		few_args = ft_strsplit(arg, ' ');
		j = 0;
		while (j < args_count)
		{
			num = validation(tools, few_args[j]);
            tools->stack_a[i++] = num;
			free(few_args[j++]);
		}
		free(few_args);
	}
	*counter = i;
}
