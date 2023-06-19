/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:59:20 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/19 18:50:28 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa_checker(t_stack *stack_a)
{
	ft_swap(stack_a);
}

void	sb_checker(t_stack *stack_b)
{
	ft_swap(stack_b);
}

void	ss_checker(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}
