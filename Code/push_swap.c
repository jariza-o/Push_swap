/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:08:10 by jariza-o          #+#    #+#             */
/*   Updated: 2023/05/21 11:08:10 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_order(int *num)
{
	int	swap;

	swap = 0;
	if (num[0] < num[1])
		ft_printf("\n");
	else
	{
		ft_printf("a\n");
		swap = num[0];
		num[0] = num[1];
		num[1] = swap;
	}
}

void	three_order(int *num)
{
	int	swap;

	swap = 0;
	if (num[0] < num[1])
	{
		if (num[1] < num[2])
			ft_printf("\n");
		else
		{
			swap = num[0];
			num[0] = num[2];
			num[2] = num[1];
			num[1] = swap;
			ft_printf("rra\n");
			swap = num[0];
			num[0] = num[1];
			num[1] = swap;
			ft_printf("sa\n");
		}
	}
	else if (num[0] > num[1])
	{
		if (num[1] < num[3])
		{
			swap = num[0];
			num[0] = num[1];
			num[1] = swap;
			ft_printf("sa\n");
		}
		else
		{
			swap = num[0];
			num[0] = num[2];
			num[2] = num[1];
			num[1] = swap;
			ft_printf("rra\n");
		}
	}
	else
	{
		if (num[1] < num[2])
		{
			swap = num[0];
			num[0] = num[1];
			num[1] = num[2];
			num[2] = swap;
			printf("ra\n");
		}
		else
		{
			swap = num[0];
			num[0] = num[1];
			num[1] = num[2];
			num[2] = swap;
			printf("ra\n");
			swap = num[0];
			num[0] = num[1];
			num[1] = swap;
			ft_printf("sa\n");
		}
	}
}

int	main(int argc, char **argv)
{
	int	*a;
	int	i;
	int	n;

	i = 0;
	n = 1;
	if (argc <= 2 || check_letter(argv) == 1) //Compruebo que haya más de un argumento y que no haya carácteres no deseados en el input
	{
		ft_printf("Error\n");
		return (0);
	}
	a = (int *)malloc(sizeof(int) * argc);
	if (a == NULL)
		return (NULL);
	while (n <= argc)
	{
		a[i] = ft_atoi(argv[n]);
		i++;
		n++;
	}
	if (check_rep(a) == 1) //Comprueba que no haya repetidos
	{
		printf("Error\n");
		free(a);
		return (0);
	}
	if (argc == 3)
		two_order(a);
	else if (argc == 4)
		three_order(a);
	else if (argc > 4)
	{

	}
	else
		ft_printf("Error\n");
	return (0);
}
