/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:06:56 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/19 01:41:38 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index_stack(t_stack *stack, int stack_size)
{
	t_stack	*aux;
	t_stack	*larguest;
	int		n;

	while (stack_size > 0)
	{
		aux = stack;
		larguest = NULL;
		n = INT_MIN;
		while (aux)
		{
			if (aux->value > n && aux->index == 0)
			{
				n = aux->value;
				larguest = aux;
				aux = stack;
			}
			aux = aux->next;
		}
		if (larguest != NULL)
			larguest->index = stack_size;
		stack_size--;
	}
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*aux;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		aux = (*stack)->next;
		free(*stack);
		*stack = aux;
	}
	*stack = NULL;
}

void	ft_free_doublepointer(char	**pointer)
{
	int	i;

	if (pointer == NULL)
		return ;
	i = 0;
	while (pointer[i])
	{
		free(pointer[i]);
		i++;
	}
	free(pointer);
}

int	ft_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
