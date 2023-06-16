/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:26:18 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/16 23:33:47 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	ft_printf("PRINT START\n");
	while (aux)
	{
		ft_printf("%d\t", aux->value);
		aux = aux->next;
	}
	ft_printf("\nPRINT END\n");
}

void	ft_print_list(t_stack *stack_a)
{
	while (stack_a)
	{
		ft_printf("v:%d\ti:%d\tpos:%d\ttp:%d\tcost_a:%d\tcost_b:%d\n", stack_a->value,
			stack_a->index, stack_a->pos, stack_a->target_pos, stack_a->cost_a,
			stack_a->cost_b);
		stack_a = stack_a->next;
	}
	ft_printf("----\n");
}
