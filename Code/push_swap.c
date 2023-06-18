/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:08:10 by jariza-o          #+#    #+#             */
/*   Updated: 2023/05/21 11:08:10 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void ft_leaks()
// {
// 	system("leaks -q push_swap");
// }

void	ft_push_swap(char **nums)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	stack_a = ft_complete_stack(nums);
	stack_b = NULL;
	stack_size = ft_stack_size(stack_a);
	ft_index_stack(stack_a, stack_size);
	// VER SI ESTO PUEDE QUE HAYA QUE HACERLO EN OTRAS FUNCIONES
	if (ft_stack_size(stack_a) == 1)
		return ;
	else if (ft_is_sorted(stack_a) == 0)
		return ;
	else if (ft_stack_size(stack_a) == 2)
		ft_two_numbers(stack_a);
	else if (ft_stack_size(stack_a) == 3)
		ft_three_numbers(&stack_a);
	else
		ft_algorithm(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}

int	main(int argc, char **argv)
{
	//atexit(ft_leaks);
	char **nums;
	int	i;

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
	if (check_error(nums) == 1 || check_rep(nums) == 1) // ¡¡¡VER SI EN ERRORES VE SI NO HAY NUMERO Y SI ESO ES UN ERROR || VER PORWUE SE TRAGA LAS LETRAS
	{
		if (i == 1)
			ft_free_doublepointer(nums);
		ft_printf("Error\n");
		return (0);
	}
	ft_push_swap(nums);
	if (i == 1)
		ft_free_doublepointer(nums);
	return (0);
}
