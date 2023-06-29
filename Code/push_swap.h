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
# include	<stdlib.h>
# include	<limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* NUMBERS FUNCTIONS */
/* Numbers in Char to Int */
int		*ft_char_to_int(char **argv);
/* Check if the numbers is sorted in stack_a */
int		ft_is_sorted(t_stack *stack_a);

/* Check Input Errors */
int		check_rep(char **argv);
int		check_letter(char **argv);
int		ft_signo(char **argv, int n, int i);
int		check_error(char **argv);
int		ft_check_min_max(char **argv);
int		ft_space_errors(char *argv);

/* STACK FUNCTIONS */
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

/* Free Memory */
/* Free Stack */
void	ft_free_stack(t_stack **stack);
/* Free double pointer */
void	ft_free_doublepointer(char	**pointer);

/* MOVEMENTS FUNCTIONS */
/* Swap functions (SA, SB, SS) */
void	ft_swap(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
/* Rotate functions (RA, RB, RR) */
void	ft_rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
/* Reverse Rotate functions (RRA, RRB, RRR) */
void	ft_reverse(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
/* Push functions (PA, PB) */
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

/* SORT OPTIONS */
/* If only exist two numbers */
void	ft_two_numbers(t_stack *stack_a);
/* If only exist three numbers */
int		ft_higest_index(t_stack *stack);
void	ft_three_numbers(t_stack **stack_a);
/* For more that three numbers */

/* ALGORITHMs FUNTIONS */
void	ft_algorithm(t_stack **stack_a, t_stack **stack_b);
/* Move all to Stack_b except three numbers */
void	ft_push_to_b(t_stack **stack_a, t_stack **stack_b);
/* Calculate position */
void	ft_position(t_stack **stack);
/* Assign target position in Stack_a */
int		ft_find_out_tp(t_stack **stack_a, int i_b, int i_a, int tp);
void	ft_target_position(t_stack **stack_a, t_stack **stack_b);
/* Calculate the movement cost */
void	ft_calculate_cost(t_stack **stack_a, t_stack **stack_b);
/* Choose the cheapest option */
void	ft_cheapest_cost(t_stack **stack_a, t_stack **stack_b);
/* Pass the negative numbers for sume the movements and choose the cheapest */
int		ft_abs(int cost);
/* Movements in the Algorithm */
void	ft_choose_move(t_stack **s_a, t_stack **s_b, int cost_a, int cost_b);
void	ft_rotate_both(t_stack **s_a, t_stack **s_b, int *cost_a, int *cost_b);
void	ft_reverse_both(t_stack **s_a, t_stack **s_b, int *cost_a, int *cost_b);
void	ft_move_stack_b(t_stack **stack_b, int	*cost_b);
void	ft_move_stack_a(t_stack **stack_a, int	*cost_a);
/* Sort the stack if isn't sorted */
void	ft_shift_stack(t_stack **stack_a);
int		ft_lowest(t_stack **stack_a);

/* Programming Tools */
void	ft_print_stack(t_stack *stack);
void	ft_print_list(t_stack *stack_a);

/* Checker */
void	ft_exit_error(t_stack **stack_a, t_stack **stack_b);
void	ft_do_op(char *op, t_stack **s_a, t_stack **s_b);
// char	**ft_mov_list(void);
void	ft_checker(char **nums);
/* Movements Checkers */
void	rra_checker(t_stack **stack_a);
void	rrb_checker(t_stack **stack_b);
void	rrr_checker(t_stack **stack_a, t_stack **stack_b);
void	ra_checker(t_stack **stack_a);
void	rb_checker(t_stack **stack_b);
void	rr_checker(t_stack **stack_a, t_stack **stack_b);
void	sa_checker(t_stack *stack_a);
void	sb_checker(t_stack *stack_b);
void	ss_checker(t_stack *stack_a, t_stack *stack_b);
void	pa_checker(t_stack **stack_a, t_stack **stack_b);
void	pb_checker(t_stack **stack_a, t_stack **stack_b);

#endif