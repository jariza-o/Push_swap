/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_movements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:27:22 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/16 21:02:49 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_choose_move(t_stack **s_a, t_stack **s_b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
		ft_rotate_both(s_a, s_b, &cost_a, &cost_b);
	else if(cost_a < 0 && cost_b < 0)
		ft_reverse_both(s_a, s_b, &cost_a, &cost_b);
	ft_move_stack_b(s_b, &cost_b);
	ft_move_stack_a(s_a, &cost_a);
	pa(s_a, s_b);
}

void	ft_rotate_both(t_stack **s_a, t_stack **s_b, int *cost_a, int *cost_b)
{
	rr(s_a, s_b);
	(*cost_a)--; //si usas *lo resta en la direccion de memoria de esa variable no en la variable que usa esta función, es decir, lo quita en donde lo llaman 
	(*cost_b)--;
}

void	ft_reverse_both(t_stack **s_a, t_stack **s_b, int *cost_a, int *cost_b)
{
	rrr(s_a, s_b);
	(*cost_a)--; //si usas *lo resta en la direccion de memoria de esa variable no en la variable que usa esta función, es decir, lo quita en donde lo llaman 
	(*cost_b)--;
}

void	ft_move_stack_b(t_stack **stack_b, int	*cost_b)
{
	if ((*stack_b)->cost_b > 0)
	{
		rb(stack_b);
		(*cost_b)--;
	}
	else if ((*stack_b)->cost_b < 0)
	{
		rrb(stack_b);
		(*cost_b)++;
	}
}

void	ft_move_stack_a(t_stack **stack_a, int	*cost_a)
{
	if ((*stack_a)->cost_b > 0)
	{
		rb(stack_a);
		(*cost_a)--;
	}
	else if ((*stack_a)->cost_a < 0)
	{
		rrb(stack_a);
		(*cost_a)++;
	}
}
