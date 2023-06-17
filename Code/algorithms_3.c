/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:41:09 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/17 20:52:58 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_shift_stack(t_stack **stack_a)
{
	int	stack_size;
	int	lowest;

	stack_size = ft_stack_size(*stack_a);
	lowest = ft_lowest(stack_a);
	if (lowest < (stack_size / 2))
	{
		while (lowest > 0)
		{
			ra(stack_a);
			lowest--;
		}
	}
	else
	{
		while (lowest < stack_size)
		{
			rra(stack_a);
			lowest++;
		}
	}
}

int	ft_lowest(t_stack **stack_a)
{
	t_stack	*aux;
	int		pos;
	int		index;

	ft_position(stack_a);
	aux = *stack_a;
	pos = aux->pos;
	index = INT_MAX;
	while (aux)
	{
		if (aux->index < index)
		{
			index = aux->index;
			pos = aux->pos;
		}
		aux = aux->next;
	}
	return (pos);
}