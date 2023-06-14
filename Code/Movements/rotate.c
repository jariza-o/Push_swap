/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:24:36 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/13 18:13:22 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = stack;
	*stack = (*stack)->next;
	last = ft_get_last_node(tmp);
	tmp->next = NULL; //porque pasa el next a NULL si despues se le asigna tmp???
	last->next = tmp;
}

void	ra(t_stack *stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}
