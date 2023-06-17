/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:44:15 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/17 22:38:30 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_complete_stack(char **argv)
{
	t_stack	*stack_a;
	int		number;
	int		i;

	stack_a = NULL;
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
	if (!new_stack)
		return (NULL);
	else if (*stack == NULL)
		*stack = new_stack;
	else
		ft_get_last_node(*stack)->next = new_stack; //la función coge y se pone en la ultima posición del stack con información, y el new_stack pasa al next que esta vacio.
	return (*stack);
}

t_stack	*ft_get_last_node(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_get_penult_node(t_stack *stack)
{
	while (stack && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_newstack(int num)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack) * 1); // Reserva memoria 1 stack
	if (stack == NULL)
		return (NULL);
	stack->value = num;
	stack->index = 0;
	stack->pos = -1; // Se pone -1 porque no esta ordenador
	stack->target_pos = -1; // Se pone -1 porque no se sabe aun en que posición debería de estar
	stack->cost_a = 0;
	stack->cost_b = 0;
	stack->next = NULL; // se pone que el next es igual a null para los controladores
	return (stack);
}
