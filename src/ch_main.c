/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:24:53 by swarner           #+#    #+#             */
/*   Updated: 2019/09/02 15:24:55 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	int	i;
	int num;

	if (argc > 1)
	{
		i = 1;
		while (argc > i)
		{
			num = validation(argv[i]);
			i++;
		}
	}
	else
		ft_error();
}