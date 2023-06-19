/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:49:16 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/19 19:38:30 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_error(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("Error\n");
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	exit(1);
}

void	ft_do_op(char *op, t_stack **s_a, t_stack **s_b)
{
	if (ft_strcmp(op, "sa") == 0)
		sa_checker(*s_a);
	else if (ft_strcmp(op, "sb") == 0)
		sb_checker(*s_b);
	else if (ft_strcmp(op, "ss") == 0)
		ss_checker(*s_a, *s_b);
	else if (ft_strcmp(op, "pa") == 0)
		pa_checker(s_a, s_b);
	else if (ft_strcmp(op, "pb") == 0)
		pb_checker(s_a, s_b);
	else if (ft_strcmp(op, "ra") == 0)
		ra_checker(s_a);
	else if (ft_strcmp(op, "rb") == 0)
		rb_checker(s_b);
	else if (ft_strcmp(op, "rr") == 0)
		rr_checker(s_a, s_b);
	else if (ft_strcmp(op, "rra") == 0)
		rra_checker(s_a);
	else if (ft_strcmp(op, "rrb") == 0)
		rrb_checker(s_b);
	else if (ft_strcmp(op, "rrr") == 0)
		rrr_checker(s_a, s_b);
	else
		ft_exit_error(s_a, s_b);
}

char	**ft_mov_list(void)
{
	char	*op_1;
	char	*op_2;
	char	*op_3;
	char	**splitted;

	op_1 = get_next_line(0);
	op_3 = NULL;
	while (op_1)
	{
		op_2 = op_3;
		if (op_2 == NULL)
			op_3 = ft_strdup(op_1);
		else
			op_3 = ft_strjoin(op_1, op_2);
		free (op_1);
		free (op_2);
		op_1 = get_next_line(0);
	}
	splitted = ft_split(op_3, '\n');
	free(op_3);
	return (splitted);
}

void	ft_checker(char **nums, int i)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**mov_lst;
	int		n;

	stack_a = ft_complete_stack(nums);
	if (i == 1)
		ft_free_doublepointer(nums);
	stack_b = NULL;
	mov_lst = ft_mov_list();
	n = 0;
	while (mov_lst[n])
	{
		ft_do_op(mov_lst[n], &stack_a, &stack_b);
		n++;
	}
	ft_free_doublepointer(mov_lst);
	if (ft_is_sorted(stack_a) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}

int	main(int argc, char **argv)
{
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
	if (check_error(nums) == 1 || check_rep(nums) == 1
		|| ft_check_min_max(nums) == 1)
	{
		if (i == 1)
			ft_free_doublepointer(nums);
		ft_printf("Error\n");
		return (0);
	}
	ft_checker(nums, i);
	return (0);
}
