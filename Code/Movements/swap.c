/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:59:20 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/12 11:59:53 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ; //cuando es una función void que no devuelve nada se pone solo return para que salga
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void	sa(t_stack *stack_a)
{
	ft_swap(stack_a);
	ft_printf("sa");
}

void	sb(t_stack *stack_b)
{
	ft_swap(stack_b);
	ft_printf("sb");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss");
}
