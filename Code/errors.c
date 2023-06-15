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
	int	i;
	int	n;

	nums = ft_char_to_int(argv);
	i = 1;
	n = 0;
	while (nums[n])
	{
		while (nums[i])
		{
			if (nums[n] == nums[i] && n != i)
			{
				free(nums);
				return (1);
			}
			i++;
		}
		n++;
		i = n;
	}
	free(nums);
	return (0);
}

int	check_error(char **argv)
{
	int			i;
	int			n;
	long int	num;

	n = 0;
	while (argv[n])
	{
		if (ft_strncmp(argv[n], "", 10) == 0) //compara
			return (1);
		i = 0;
		while (argv[n][i])
		{
			if ((argv[n][i] == '-' || argv[n][i] == '+') &&
			(argv[n][i + 1] == '-' || argv[n][i + 1] == '+'))
				return (1);
			if (!ft_isdigit(argv[n][i]))
				return (1);
			i++;
		}
		num = ft_atol(argv[n]);
		if (num < INT_MIN || num > INT_MAX) //Comprobar si el numero está entre el número mínimo y el número maximo que soporta un long int
			return (1);
		n++;
	}
	return (0);
}
