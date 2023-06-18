/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:15:49 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/19 01:33:11 by jariza-o         ###   ########.fr       */
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
	nums = (int *)malloc(sizeof(int) * (i));
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

int	ft_is_sorted(t_stack *stack_a)
{
	t_stack	*aux;

	aux = stack_a;
	while (aux->next != NULL)
	{
		if (aux->value < aux->next->value)
			aux = aux->next;
		else
			return (1);
	}
	return (0);
}

void	ft_two_numbers(t_stack *stack_a)
{
	if (stack_a->index > stack_a->next->index)
		sa(stack_a);
}

void	ft_three_numbers(t_stack **stack_a)
{
	if ((*stack_a)->index == ft_higest_index(*stack_a))
	{
		ra(stack_a);
		if (ft_is_sorted(*stack_a) == 1)
			sa(*stack_a);
	}
	else if ((*stack_a)->next->index == ft_higest_index(*stack_a))
	{
		rra(stack_a);
		if (ft_is_sorted(*stack_a) == 1)
			sa(*stack_a);
	}
	else if ((*stack_a)->next->next->index == ft_higest_index(*stack_a)
		&& ft_is_sorted(*stack_a) == 1)
		sa(*stack_a);
}
