/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:26:18 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/13 18:29:11 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	ft_printf("PRINT START\n");
	while (stack)
	{
		ft_printf("%d\t", stack->value);
		stack = stack->next;
	}
	ft_printf("\nPRINT END\n");
}
