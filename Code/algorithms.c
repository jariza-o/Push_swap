/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:04:26 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/16 00:52:32 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_to_b(&stack_a, &stack_b);//paso todo menos 3 a stack_b
	ft_three_numbers(stack_a);
	
}

void	ft_push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	n;

	n = ft_stack_size(*stack_a);
	while (n > (n - 3))
	{
		pb(*stack_a, *stack_b);
		n--;
	}
}

void	ft_target_position(t_stack **stack_a, t_stack **stack_b)//comprobar si pone bien en stack_b la posición donde debería estar en stack_a
{
	t_stack	*aux_a;
	t_stack	*aux_b;
	int		i;

	aux = *stack_a;
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
			aux_a = *stack;
		}
		else
			aux_a = aux_a->next;
	}
}

void	ft_calculate_cost(t_stack **stack_a, t_stack **stack_b)
{
	int	up_a;
	int	down_a;
	int	up_b;
	int	down_b;
	t_stack	*aux;
	t_stack	*last_b;

	aux = *stack_a;
	up_a = aux->pos - 1;
	while (last_b->next != NULL)
		last_b = last_b->next;
	down_a = last_b->pos - aux->pos;




}
void	ft_cheapest_cost(t_stack **stack_a, t_stack **stack_b);