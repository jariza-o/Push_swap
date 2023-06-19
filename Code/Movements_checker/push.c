/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:27:04 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/19 18:42:48 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa_checker(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_a == NULL)
	{
		*stack_a = tmp;
		(*stack_a)->next = NULL;
	}
	else
	{
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
}

void	pb_checker(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_b == NULL)
	{
		*stack_b = tmp;
		(*stack_b)->next = NULL;
	}
	else
	{
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
}
