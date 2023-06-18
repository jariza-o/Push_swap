/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:44:15 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/19 01:34:31 by jariza-o         ###   ########.fr       */
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
		ft_get_last_node(*stack)->next = new_stack;
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

	stack = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (stack == NULL)
		return (NULL);
	stack->value = num;
	stack->index = 0;
	stack->pos = -1;
	stack->target_pos = -1;
	stack->cost_a = 0;
	stack->cost_b = 0;
	stack->next = NULL;
	return (stack);
}
