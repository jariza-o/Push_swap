/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:27:04 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/15 20:17:58 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
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
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
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
	ft_printf("pb\n");
}
