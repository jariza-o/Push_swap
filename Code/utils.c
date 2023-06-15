/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:26:18 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/15 13:35:48 by jariza-o         ###   ########.fr       */
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
