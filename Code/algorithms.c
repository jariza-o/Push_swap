/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:04:26 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/19 01:32:41 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_to_b(stack_a, stack_b);
	ft_three_numbers(stack_a);
	while (*stack_b)
	{
		ft_target_position(stack_a, stack_b);
		ft_calculate_cost(stack_a, stack_b);
		ft_cheapest_cost(stack_a, stack_b);
	}
	if (ft_is_sorted(*stack_a) == 1)
		ft_shift_stack(stack_a);
}

void	ft_push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = ft_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (i < stack_size && pushed < (stack_size / 2) && stack_size > 6)
	{
		if ((*stack_a)->index <= (stack_size / 2))
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while ((stack_size - pushed) > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

void	ft_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;
	int		tp;

	ft_position(stack_a);
	ft_position(stack_b);
	aux = *stack_b;
	tp = 0;
	while (aux)
	{
		tp = ft_find_out_tp(stack_a, aux->index, INT_MAX, 0);
		aux->target_pos = tp;
		aux = aux->next;
	}
}

void	ft_calculate_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux_a;
	int		size_a;
	t_stack	*aux_b;
	int		size_b;

	aux_a = *stack_a;
	size_a = ft_stack_size(*stack_a);
	aux_b = *stack_b;
	size_b = ft_stack_size(*stack_b);
	while (aux_b)
	{
		aux_b->cost_b = aux_b->pos;
		if (aux_b->pos > (size_b / 2))
			aux_b->cost_b = (size_b - aux_b->pos) * -1;
		aux_b->cost_a = aux_b->target_pos;
		if (aux_b->target_pos > (size_a / 2))
			aux_b->cost_a = (size_a - aux_b->target_pos) * -1;
		aux_b = aux_b->next;
	}
}

void	ft_cheapest_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;
	int		cost_a;
	int		cost_b;
	int		cheapest;

	aux = *stack_b;
	cheapest = INT_MAX;
	while (aux)
	{
		if (ft_abs(aux->cost_a) + ft_abs(aux->cost_b) < ft_abs(cheapest))
		{
			cheapest = ft_abs(aux->cost_a) + ft_abs(aux->cost_b);
			cost_a = aux->cost_a;
			cost_b = aux->cost_b;
		}
		aux = aux->next;
	}
	ft_choose_move(stack_a, stack_b, cost_a, cost_b);
}
