/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:37:39 by jariza-o          #+#    #+#             */
/*   Updated: 2023/05/25 00:37:39 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//nose si SA es con ** o con *, creo que puede ser con la segunda
t_stack	**sa(t_stack **stack)
{
	t_stack *aux1;
	t_stack	*aux2;

	aux1 = (*stack);
	aux2 = (*stack)->next->next;
	(*stack)->next->next = aux1;
	(*stack)->next = aux2;
	return (stack);

}

void	pb(int *a, int *b)
{
	int	*swap_a;
	int	*swap_b;
	int	i;
	int	n;

	i = 1;
	n = 0;

	while (a[i])
	{
		swap_a[n] = a[i];
		n++;
		i++;
	}
	swap_b[0] = a[0];
	i = 0;
	n = 1;
	while (b[i])
	{
		swap_b[n] = b[i];
		n++;
		i++;
	}
	a = swap_a;
	b = swap_b;
}

void	rra(int *a, int *b)
{
	
}