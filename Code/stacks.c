/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:44:15 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/15 17:23:16 by jariza-o         ###   ########.fr       */
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
	};
	return (stack_a);
}

t_stack	*ft_add_to_last(t_stack **stack, t_stack *new_stack)
{
	if (new_stack == NULL)
	{
		return (NULL);
	}
	else if (*stack == NULL)
		*stack = new_stack;
	else
		ft_get_last_node(*stack)->next = new_stack; //la función coge y se pone en la ultima posición del stack con información, y el new_stack pasa al next que esta vacio.
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
	stack = (t_stack *)malloc(sizeof(t_stack) * 1); // Reserva memoria 1 stack
	if (stack == NULL)
		return (NULL);
	stack->value = num;
	stack->index = 0;
	stack->pos = -1; // Se pone -1 porque no esta ordenador
	stack->target_pos = -1; // Se pone -1 porque no se sabe aun en que posición debería de estar
	stack->cost_a = 0;
	stack->cost_b = 0;
	stack->next = NULL; // se pone que el next es igual a null para los controladores
	return (stack);
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
