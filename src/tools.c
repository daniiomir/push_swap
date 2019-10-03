/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:41:09 by swarner           #+#    #+#             */
/*   Updated: 2019/10/03 22:34:19 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_valies(t_tools *tools)
{
	tools->count_of_num = 0;
	tools->size_a = 0;
	tools->size_b = 0;
	tools->error = 0;
	tools->debug = 0;
	tools->color = 0;
	tools->is_visible = 0;
	tools->op_count = 0;
}

int		validation(t_tools *tools, char *arg)
{
	ssize_t	num;

	num = ft_atoi(arg);
	if (num > 2147483647 || num < -2147483648)
		tools->error = 1;
	if ((num + '0' != arg[0] && num == 0)
	|| (-num + '0' != arg[1] && num == -1))
		tools->error = 1;
	return (num);
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	len_for_stack(int argc, char **argv, t_tools *tools)
{
	int		i;
	size_t	len;

	i = 1;
	while (argc > i)
	{
		len = ft_count_words(argv[i], ' ');
		tools->count_of_num += len;
		tools->size_a += len;
		i++;
	}
	if (tools->debug)
	{
		tools->count_of_num--;
		tools->size_a--;
	}
	if (tools->debug && tools->color)
	{
		tools->count_of_num--;
		tools->size_a--;
	}
}

void	handle_arg(char *arg, t_tools *tools, size_t *counter)
{
	size_t	i;
	size_t	j;
	size_t	args_count;
	char	**few_args;

	i = *counter;
	args_count = ft_count_words(arg, ' ');
	if (args_count == 1)
		tools->stack_a[i++] = validation(tools, arg);
	else
	{
		few_args = ft_strsplit(arg, ' ');
		j = 0;
		while (j < args_count)
		{
			tools->stack_a[i++] = validation(tools, few_args[j]);
			free(few_args[j++]);
		}
		free(few_args);
	}
	*counter = i;
}
