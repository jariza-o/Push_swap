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
// char	**ft_splited(char **argv);

/* NUMBERS FUNTIONS */
/* Count Numbers */
int		ft_count_nums(char **argv);
/* Numbers in Char to Int */
int		*ft_char_to_int(char **argv);
/* Check if the numbers is sorted in stack_a */
int	ft_is_sorted(t_stack *stack_a);

/* Check Input Errors */
int		check_rep(char **argv);
int		check_letter(char **argv);
int		check_error(char **argv);

/* STACK FUNTIONS */
/* Get the last Node with information */
t_stack	*ft_get_last_node(t_stack *stack);
/* Get the penultimate Node with information */
t_stack	*ft_get_penult_node(t_stack *stack);
/* Move the Numbers tu the Stacks */
t_stack	*ft_complete_stack(char **argv);
t_stack	*ft_add_to_last(t_stack **stack, t_stack *new_stack);
t_stack	*ft_newstack(int num);
/* Revise the Stack size */
int		ft_stack_size(t_stack *stack);
/* Put Index in the Stacks */
void	ft_index_stack(t_stack *stack, int stack_size);

/* MOVMENTS FUNTIONS */
/* Swap funtions (SA, SB, SS) */
void	ft_swap(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
/* Rotate funtions (RA, RB, RR) */
void	ft_rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
/* Reverse Rotate funtions (RRA, RRB, RRR) */
void	ft_reverse(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
/* Push funtions (PA, PB) */
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

/* SORT OPTIONS */
/* If only exist two numbers */
void	ft_two_numbers(t_stack *stack_a);
/* If only exist three numbers */
void	ft_three_numbers(t_stack **stack_a);
/* For more that three numbers */

/* ALGORITHMS FUNTIONS */
void	ft_algorithm(t_stack **stack_a, t_stack **stack_b);
/* Move all to Stack_b except three numbers */
void	ft_push_to_b(t_stack **stack_a, t_stack **stack_b);
/* Assign target position in Stack_a */
void	ft_target_position(t_stack **stack_a, t_stack **stack_b);
/* Calculate the movement cost */
void	ft_calculate_cost(t_stack **stack_a, t_stack **stack_b);

/* Programming Tools */
void	ft_print_stack(t_stack *stack);

#endif