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

void ft_leaks()
{
	system("leaks -q push_swap");
}

void	two_order(int *num)
{
	int	swap;

	swap = 0;
	if (num[0] < num[1])
		ft_printf("\n");
	else
	{
		ft_printf("a\n");
		swap = num[0];
		num[0] = num[1];
		num[1] = swap;
	}
}

void	three_order(int *num)
{
	int	swap;

	swap = 0;
	if (num[0] < num[1])
	{
		if (num[1] < num[2])
			ft_printf("\n");
		else
		{
			swap = num[0];
			num[0] = num[2];
			num[2] = num[1];
			num[1] = swap;
			ft_printf("rra\n");
			swap = num[0];
			num[0] = num[1];
			num[1] = swap;
			ft_printf("sa\n");
		}
	}
	else if (num[0] > num[1])
	{
		if (num[1] < num[3])
		{
			swap = num[0];
			num[0] = num[1];
			num[1] = swap;
			ft_printf("sa\n");
		}
		else
		{
			swap = num[0];
			num[0] = num[2];
			num[2] = num[1];
			num[1] = swap;
			ft_printf("rra\n");
		}
	}
	else
	{
		if (num[1] < num[2])
		{
			swap = num[0];
			num[0] = num[1];
			num[1] = num[2];
			num[2] = swap;
			printf("ra\n");
		}
		else
		{
			swap = num[0];
			num[0] = num[1];
			num[1] = num[2];
			num[2] = swap;
			printf("ra\n");
			swap = num[0];
			num[0] = num[1];
			num[1] = swap;
			ft_printf("sa\n");
		}
	}
}

void	ft_push_swap(char **nums)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = ft_complete_stack(nums);
	stack_b = NULL;


	// VER SI ESTO PUEDE QUE HAYA QUE HACERLO EN OTRAS FUNCIONES
	if (ft_nnums(nums) == 1)
		return (0); // NOSE SI PARA QUE NO HAGA NADA ES ASI
	else if (ft_nnums(nums) == 2)
		// LLAMAR A FUNCION PARA DOS NUMEROS Y DENTRO DE ESTA FUNCION CREAR EN MOVEMMENT SA
	else if (ft_nnums(nums) == 3)
		// LLAMAR A FUNCION PARA 3 NUMEROS Y DENTRO DE ESTA FUNCION CREAR EN MOVEMMENT LOS MOVS NECESARIOS
	else
		// CREAR LO NECESARIO SI HAY MUCHOS NUEMROS
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
		nums = ft_splited(argv);
	else
		nums = ++argv;
	if (check_error(nums) == 1 || check_rep(nums) == 1) // ¡¡¡VER SI EN ERRORES VE SI NO HAY NUMERO Y SI ESO ES UN ERROR
	{
		//Liberar nums si está usandose (argc == 2)
		ft_printf("Error\n");
		return (0);
	}
	ft_push_swap(nums);
	//Liberar nums si está usandose (argc == 2)
	return (0);
}


*/comprueba impriemdo y leaks

1º comprobar num arg y errores
2º pasar a la lista y inexas
3 comprobar nº de nºs : 2 -> sa; 3 -> 5 casos; +3-> pushb todos -3
4 ordenas los 3

----repetir en bucle ------
5 target posi
6 calculo de costes
7 elgir coste mas barato
8 ejectura el movimiento

3º preparacion para ordenar