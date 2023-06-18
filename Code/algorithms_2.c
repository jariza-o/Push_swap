/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:48:53 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/17 17:51:06 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_higest_index(t_stack *stack)
{
	int	highest;

	highest = stack->index;
	while (stack)
	{
		if (highest < stack->index)
			highest = stack->index;
		stack = stack->next;
	}
	return (highest);
}

int	ft_abs(int cost)
{
	if (cost < 0)
		return (-cost);
	return (cost);
}

void	ft_position(t_stack **stack)
{
	t_stack	*aux;
	int		i;

	aux = *stack;
	i = 0;
	while (aux)
	{
		aux->pos = i;
		aux = aux->next;
		i++;
	}
}

int	ft_find_out_tp(t_stack **stack_a, int i_b, int i_a, int tp)
{
	t_stack	*aux;

	aux = *stack_a;
	while (aux)
	{
		if (aux->index > i_b && aux->index < i_a)
		{
			i_a = aux->index;
			tp = aux->pos;
		}
		aux = aux->next;
	}
	if (i_a != INT_MAX)
		return (tp);
	aux = *stack_a;
	while (aux)
	{
		if (aux->index < i_a)
		{
			i_a = aux->index;
			tp = aux->pos;
		}
		aux = aux->next;
	}
	return (tp);
}
