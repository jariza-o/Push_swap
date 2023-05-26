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
char	**ft_splited(char **argv[]);

/* Check Input Errors */
int	check_rep(int *num);
int	check_letter(char **argv);


#endif