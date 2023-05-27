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

int	check_rep(char **argv)
{
	int	*nums;
	int	size;
	int	i;
	int	n;

	size = 0;
	i = 0;
	n = 0;
	while (argv[n++]) //ver si el n++ hay esta bien
		size++;
	nums = (int *)malloc(sizeof(int) * (size + 1)); //tiene que sumar el +1??
	if (nums == NULL)
		return (NULL);
	n = 0;
	while (argv[n++]) //ver si el n++ hay esta bien
		nums[i] = ft_atol(argv[n]);
	i = 1;
	n = 0;
	while (nums[n])
	{
		while (nums[i])
		{
			if (nums[n] == nums[i] && n != i)
				return (1);
			i++;
		}
		n++;
	}
	free(nums); //ver si hay que liberar o no
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
