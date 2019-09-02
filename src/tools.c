/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:41:09 by swarner           #+#    #+#             */
/*   Updated: 2019/09/02 15:41:11 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
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
