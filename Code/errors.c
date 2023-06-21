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

int	ft_signo(char **argv, int n, int i)
{
	if ((argv[n][i] == '-' || argv[n][i] == '+') &&
		(argv[n][i + 1] == '-' || argv[n][i + 1] == '+' ||
		argv[n][i + 1] == '\0'))
		return (1);
	return (0);
}

int	check_error(char **argv)
{
	int			i;
	int			n;

	n = 0;
	while (argv[n])
	{
		i = 0;
		if (ft_strcmp(argv[n], "") == 0)
			return (1);
		while (argv[n][i])
		{
			if (ft_signo(argv, n, i) == 1)
				return (1);
			if ((argv[n][i] == '-' || argv[n][i] == '+'))
				i++;
			while (argv[n][i])
			{
				if (!ft_isdigit(argv[n][i]))
					return (1);
				i++;
			}
		}
		n++;
	}
	return (0);
}

int	ft_check_min_max(char **argv)
{
	int			n;
	long int	num;

	n = 0;
	while (argv[n])
	{
		num = ft_atol(argv[n]);
		if (num < INT_MIN || num > INT_MAX)
			return (1);
		n++;
	}
	return (0);
}

int	ft_space_errors(char *argv)
{
	int	n;

	n = 0;
	while (argv[n])
	{
		if (argv[n] != ' ' && argv[n] != '\t')
			return (0);
		n++;
	}
	return (1);
}
