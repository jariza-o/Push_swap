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
	t_stack	*rotated;
	t_stack	*aux;

	aux = stack;
	while (aux)
	{
		if (aux->next)
			aux = aux->next;
		else
			break ;
	}
	rotated = aux;
	rotated->next = stack->next;
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
