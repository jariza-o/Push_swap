/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:15:49 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/13 18:16:39 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_char_to_int(char **argv)
{
	int	*nums;
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (argv[n++])
		i++;
	nums = (int *)malloc(sizeof(int) * (i)); //tiene que sumar el +1??
	if (nums == NULL)
		return (NULL);
	n = 0;
	i = 0;
	while (argv[n])
	{
		nums[i] = ft_atoi(argv[n]);
		i++;
		n++;
	}
	return (nums);
}

int	ft_count_nums(char **argv)
{
	int	n;

	n = 0;
	while (argv[n])
		n++;
	return (n);
}

void	ft_two_numbers(t_stack *stack_a)
{
	if (stack_a->index > stack_a->next->index)
		sa(stack_a);
}

void	ft_three_numbers(t_stack *stack_a)
{
	//if (stack_a->index == 1)
	//{
		//if (stack_a->next->index == 2)
		//	return ;
		//else
		//{
			//rra(stack_a);
		//	sa(stack_a);
		//}
	//}
	//else if (stack_a->index == 2)
	//{
	//	ft_printf("222222222\n");
	//	if (stack_a->next->index == 1)
	//		sa(stack_a);
		//else
			//rra(stack_a);
	//}
	//else
	if (stack_a->index == 3)
	{
		ft_printf("33333333\n");
		ra(stack_a);
		if (stack_a->index != 1)
			sa(stack_a);
	}
}
