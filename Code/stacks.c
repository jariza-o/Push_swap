/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:44:15 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/09 14:16:58 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_complete_stack(char **argv)
{
	t_stack	*stack_a;
	int		number;
	int		i;

	i = 0;
	while (argv[i])
	{
		number = ft_atoi(argv[i]);
		ft_add_to_last(&stack_a, ft_newstack(number));
		i++;
	}
	return (stack_a);
}

t_stack	*ft_add_to_last(t_stack **stack, t_stack *new_stack)
{
	if (new_stack == NULL)
		return (NULL);
	else if (*stack == NULL)
		*stack = new_stack;
	else
	{
		while (*stack && (*stack)->next != '\0')
			*stack = (*stack)->next;
		(*stack)->next = new_stack;
	}
	return (*stack);
}

t_stack	*ft_newstack(int num)
{
	t_stack	*stack;
	stack = (t_stack *)malloc(sizeof(t_stack) * 1); // Reserva memoria 1 stack
	if (stack == NULL)
		return(NULL);
	stack->value = num;
	stack->index = 0;
	stack->pos = -1; // Se pone -1 porque no esta ordenador
	stack->target_pos = -1; // Se pone -1 porque no se sabe aun en que posición debería de estar
	stack->cost_a = 0;
	stack->cost_b = 0;
	stack->next = NULL; // se pone que el next es igual a null para los controladores
	return (stack);
}

int	ft_stack_size(t_stack *stack)
{
	int	size;

	size = 0;

	if (!stack)
		return (0);
	while(stack != '\0')
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

void	ft_index_stack(t_stack *stack, int stack_size)
{
	int	*numbers;
	t_stack *stack_copy;
	int	i;

	stack_copy = stack_a;
	i = 0;
	if (stack_size > 0)
	{
		while (stack_copy != '\0')
		{
			numbers[i] = stack_copy->index;
			stack_copy = stack_copy->next;
			i++;
		}
	}
}