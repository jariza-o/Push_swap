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

int	check_error(char **argv)
{
	int			i;
	int			n;
	long int	num;

	i = 0;
	n = 0;
	while (argv[n])
	{
		while (argv[n][i])
		{
			if (ft_strcmp("", argv[n]) == 0)
				return (1);
			else if ((argv[n][i] == '-' || argv[n][i] == '+') &&
			(argv[n][i + 1] == '-' || argv[n][i + 1] == '+'))
				return (1);
			else if (argv[n][i] < '0' && argv[n][i] > '9')
				return (1);
			i++;
		}
		num = ft_atol(argv[n]);
		if (num < INT_MIN || num > INT_MAX) //Comprobar si el numero está entre el número mínimo y el número maximo que soporta un long int
			return (1);
		i = 0;
		n++;
	}
	return (0);
}
