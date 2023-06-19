/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:36:25 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/19 18:43:27 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra_checker(t_stack **stack_a)
{
	ft_reverse(stack_a);
}

void	rrb_checker(t_stack **stack_b)
{
	ft_reverse(stack_b);
}

void	rrr_checker(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse(stack_a);
	ft_reverse(stack_b);
}
