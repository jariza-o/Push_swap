/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:38:00 by jariza-o          #+#    #+#             */
/*   Updated: 2023/05/21 11:38:00 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	"libft/libft.h"
# include	"ft_printf/ft_printf.h"
# include	<stdlib.h>
# include	<limits.h>

typedef struct s_stack
{
	int	value;
	int	index;
	int	pos;
	int	target_pos;
	int	cost_a;
	int	cost_b;
	struct s_stack	*next;
}	t_stack;

/* Take numbers */
char	**ft_splited(char **argv);

/* Check Input Errors */
int		check_rep(int *num);
int		check_letter(char **argv);

/* STACK FUNTIONS */
/* Move the Numbers tu the Stacks */
t_stack	*ft_complete_stack(char **argv);
t_stack	*ft_add_to_last(t_stack **stack, t_stack *new_stack);
t_stack	*ft_newstack(int num);
/* Revise the Stack size */
int		ft_stack_size(t_stack *stack);
/* Put Index in the Stacks*/
void	ft_index_stack(t_stack *stack, int stack_size);

/* Count Numbers */
int		ft_count_nums(char **argv);

#endif