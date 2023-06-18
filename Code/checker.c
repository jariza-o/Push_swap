/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:49:16 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/18 21:31:53 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void ft_leaks()
// {
// 	system("leaks -q push_swap");
// }

void	ft_exit_error(t_stack **stack_a, t_stack **stack_b, char **nums, int i)
{
	ft_printf("Error\n");
	if (i == 1)
		ft_free_doublepointer(nums);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	exit(1);
}

void	ft_do_op(char *op, t_stack **s_a, t_stack **s_b, char **nums, int i)
{
	if (ft_strcmp(op, "sa\n") == 0)
		sa(*s_a);
	else if (ft_strcmp(op, "sb\n") == 0)
		sb(*s_b);
	else if (ft_strcmp(op, "ss\n") == 0)
		ss(*s_a, *s_b);
	else if (ft_strcmp(op, "pa\n") == 0)
		pa(s_a, s_b);
	else if (ft_strcmp(op, "pb\n") == 0)
		pb(s_a, s_b);
	else if (ft_strcmp(op, "ra\n") == 0)
		ra(s_a);
	else if (ft_strcmp(op, "rb\n") == 0)
		rb(s_b);
	else if (ft_strcmp(op, "rr\n") == 0)
		rr(s_a, s_b);
	else if (ft_strcmp(op, "rra\n") == 0)
		rra(s_a);
	else if (ft_strcmp(op, "rrb\n") == 0)
		rrb(s_b);
	else if (ft_strcmp(op, "rrr\n") == 0)
		rrr(s_a, s_b);
	else
		ft_exit_error(s_a, s_b, nums, i);
}

void	ft_checker(char **nums, int i)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*op;

	stack_a = ft_complete_stack(nums);
	stack_b = NULL;
	op = get_next_line(0);
	while (op)
	{
		ft_do_op(op, &stack_a, &stack_b, nums, i);
		free (op);
		op = get_next_line(0);
	}
	if (ft_is_sorted(stack_a) == 0)
		ft_printf("OK");
	else
		ft_printf("KO");
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}

int	main(int argc, char **argv)
{
	// atexit(ft_leaks);
	char	**nums;
	int		i;

	i = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		i = 1;
	}
	else
		nums = ++argv;
	if (check_error(nums) == 1 || check_rep(nums) == 1)
	{
		if (i == 1)
			ft_free_doublepointer(nums);
		ft_printf("Error\n");
		return (0);
	}
	ft_checker(nums, i);
	if (i == 1)
		ft_free_doublepointer(nums);
	return (0);
}