/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:06:56 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/17 22:25:09 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index_stack(t_stack *stack, int stack_size)
{
	t_stack	*aux;
	t_stack	*larguest;
	int		n;

	while (stack_size > 0)
	{
		aux = stack;
		larguest = NULL; //se usa para almacenar el stack que es el numero más grand equ eno está indexado
		n = INT_MIN; // Valor minimo que puede tener, se usa para comparar que los otros numeros son mayores que este la primera vez
		while (aux)
		{
			if (aux->value > n && aux->index == 0) // si el numero es mayor que el anterior y no esta indexado
			{
				n = aux->value; // n pasa a ser el nuevo porque es el más grande de los que se ha visto
				larguest = aux; // larguest es igual a aux, porque hasta este momento es el numero más grande que se ha visto
				aux = stack; // aux vuelve a empezar desde el principio, despues se salta el primero ya que se ha comprobado ya
			}
			aux = aux->next; // si no entra en el if(porque el siguiente numero sea mas chico que alguno de los anteriores o porque este indexado) hace un next, asi recorre todo el stack, cuando encuentre el mas grande sin indexar no va a entrar al if y larguest va a ser el mas grande
		}
		if (larguest != NULL) // como larguest es el mas grande en ese momento, se le pone el index que es el mismo que el stack_size porque se va restando -1
			larguest->index = stack_size;
		stack_size--;
	}
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*aux;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		aux = (*stack)->next;
		free(*stack);
		*stack = aux;
	}
	*stack = NULL;
}

void	ft_free_doublepointer(char	**pointer)
{
	int	i;

	if (pointer == NULL)
		return ;
	i = 0;
	while (pointer[i])
	{
		free(pointer[i]);
		i++;
	}
	free(pointer);
}

int	ft_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
