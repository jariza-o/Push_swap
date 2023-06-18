# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 11:56:41 by jariza-o          #+#    #+#              #
#    Updated: 2023/06/18 17:13:00 by jariza-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		push_swap

SRC =		push_swap.c errors.c numbers.c stacks.c algorithms.c\
			Movements/swap.c Movements/rotate.c Movements/reverse.c Movements/push.c Movements/algorithms_movements.c\
			algorithms_2.c algorithms_3.c stacks_2.c utils.c \

OBJT =		$(SRC:.c=.o)

CFLAGS =	-Wall -Werror -Wextra

LIBFT =		libft/libft.a

FT_PRINTF =	ft_printf/libftprintf.a

.c.o:
		gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME): ${OBJT}
			make -C libft
			make -C ft_printf
			gcc ${CFLAGS} ${OBJT} ${LIBFT} ${FT_PRINTF} -o ${NAME}

clean:		
			make -C libft fclean
			make -C ft_printf fclean
			rm -f ${OBJT}

fclean: 	clean
			rm -f ${NAME}

re: 		fclean all

py:	all
	python3 python_visualizer.py `ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`

.PHONY: all clean fclean re py