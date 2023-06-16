/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:04:26 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/16 13:46:03 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_to_b(stack_a, stack_b);//paso todo menos 3 a stack_b
	ft_three_numbers(stack_a);
	while (*stack_b)
	{
		ft_target_position(stack_a, stack_b);
		ft_calculate_cost(stack_a, stack_b);
	}
}

void	ft_push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	n;

	n = ft_stack_size(*stack_a);
	while (n > 3)
	{
		pb(stack_a, stack_b);
		n--;
	}
}

void	ft_target_position(t_stack **stack_a, t_stack **stack_b)//comprobar si pone bien en stack_b la posición donde debería estar en stack_a
{
	t_stack	*aux_a;
	t_stack	*aux_b;
	int		i;

	aux_a = *stack_a;
	aux_b = *stack_b;
	i = 0;
	while (aux_a)
	{
		aux_a->pos = i;
		aux_a = aux_a->next;
		i++;
	}
	i = 1;
	while (aux_b)
	{
		aux_b->pos = i;
		aux_b = aux_b->next;
		i++;
	}
	aux_a = *stack_a;
	aux_b = *stack_b;
	while (aux_b)
	{
		if (aux_b->pos < aux_a->pos)
		{
			aux_b->target_pos = aux_a->pos;
			aux_b = aux_b->next;
			aux_a = *stack_a;
		}
		else
			aux_a = aux_a->next;
	}
}

void	ft_calculate_cost(t_stack **stack_a, t_stack **stack_b) //entender bien la funcion
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
		if (aux_b->pos > (size_b / 2)) //los eleementos que se encuenytra más cerca del final dará nº negativo
			aux_b->cost_b = (size_b - aux_b->pos) * -1;
		ft_printf("El cost_b del valor %d es %d\n", aux_b->value, aux_b->cost_b);
		aux_b->cost_a = aux_b->target_pos;
		if (aux_b->target_pos > (size_a / 2)) //los elementos cuyo objetivo esta cerca del final son nº negaticos
			aux_b->cost_a = (size_a - aux_b->target_pos) * -1;
		ft_printf("El cost_a del valor %d es %d\n", aux_b->value, aux_b->cost_a);
		aux_b = aux_b->next;
	}
}

// void	ft_cheapest_cost(t_stack **stack_a, t_stack **stack_b)
// {

// }
