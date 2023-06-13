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

static void ft_leaks()
{
	system("leaks -q push_swap");
}

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
	if (ft_count_nums(nums) == 1)
		return ; // NOSE SI PARA QUE NO HAGA NADA ES ASI
	else if (ft_count_nums(nums) == 2)
		ft_two_numbers(stack_a);
	else if (ft_count_nums(nums) == 3)
		ft_three_numbers(stack_a);
//	else
		// CREAR LO NECESARIO SI HAY MUCHOS NUEMROS
	ft_printf("________ STACK PRINTED _____________\n");

	int gh = 0;
	while(gh < 10)
	{
		ft_printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
		gh++;
	}
}

int	main(int argc, char **argv)
{
	atexit(ft_leaks);
	char **nums;
	int	i;
	int	n;

	i = 0;
	n = 1;
	if (argc < 2)
		return (0);
	if (argc == 2)
		nums = ft_split(argv[1], ' ');
	else
		nums = ++argv;
	if (check_error(nums) == 1 || check_rep(nums) == 1) // ¡¡¡VER SI EN ERRORES VE SI NO HAY NUMERO Y SI ESO ES UN ERROR || VER PORWUE SE TRAGA LAS LETRAS
	{
		//Liberar nums si está usandose (argc == 2) Marina libera con función especial ver si lo puedo hacer sin esta funcion
		ft_printf("Error\n");
		return (0);
	}
	ft_push_swap(nums);
	//Liberar nums si está usandose (argc == 2) Marina libera con función especial ver si lo puedo hacer sin esta funcion
 	return (0);
}

// MAIN DE PRUEBAS
// int	main(void)
// {
// 	t_stack	*stack;

// 	stack = NULL;
// 	stack->value = 1;
// 	stack->index = 1;
// 	stack->next->value = 2;
// 	stack->next->index = 2;
// 	sa(stack);
// 	ft_printf("\n\n %d %d \n", stack->value, stack->next->value);
// }
// */comprueba impriemdo y leaks

// 1º comprobar num arg y errores
// 2º pasar a la lista y inexas
// 3 comprobar nº de nºs : 2 -> sa; 3 -> 5 casos; +3-> pushb todos -3
// 4 ordenas los 3

// ----repetir en bucle ------
// 5 target posi
// 6 calculo de costes
// 7 elgir coste mas barato
// 8 ejectura el movimiento

// 3º preparacion para ordenar