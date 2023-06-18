/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:36:25 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/15 17:33:30 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reverse(t_stack **stack)
{
	t_stack	*penult;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = ft_get_last_node(*stack);
	penult = ft_get_penult_node(*stack);
	last->next = (*stack);
	penult->next = NULL;
	*stack = last;
}

void	rra(t_stack **stack_a)
{
	ft_reverse(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	ft_reverse(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse(stack_a);
	ft_reverse(stack_b);
	ft_printf("rrr\n");
}
