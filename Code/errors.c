/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:07:12 by jariza-o          #+#    #+#             */
/*   Updated: 2023/05/25 00:07:12 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_rep(int *num)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	while (num[n])
	{
		while (num[i])
		{
			if (num[n] == num[i] && n != i)
			{
				printf("Error\n");
				return (1);
			}
			i++;
		}
		n++;
	}
	return (0);
}

int	check_letter(char **argv)
{
	int	i;
	int	n;

	while (argv[n])
	{
		while (argv[n][i])
		{
			if (argv[n][i] != '-' && argv[n][i] < '0' && argv[n][i] > '9')
				return(1);
			i++;
		}
		i = 0;
		n++;
	}
	return (0);
}
