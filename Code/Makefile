# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 11:56:41 by jariza-o          #+#    #+#              #
#    Updated: 2023/06/18 20:25:16 by jariza-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		push_swap

BONUS =		checker

SRC =		push_swap.c errors.c numbers.c stacks.c algorithms.c\
			Movements/swap.c Movements/rotate.c Movements/reverse.c Movements/push.c Movements/algorithms_movements.c\
			algorithms_2.c algorithms_3.c stacks_2.c utils.c \

OBJT =		$(SRC:.c=.o)

SRCBONUS =	checker.c stacks_2.c numbers.c errors.c stacks.c algorithms_2.c \
			Movements/swap.c Movements/rotate.c Movements/reverse.c Movements/push.c \

BONUS_OBJT =	$(SRCBONUS:.c=.o)

CFLAGS =	-Wall -Werror -Wextra

LIBFT =		libft/libft.a

.c.o:
		gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME): ${OBJT}
			make -C libft
			gcc ${CFLAGS} ${OBJT} ${LIBFT} -o ${NAME}

$(BONUS): ${BONUS_OBJT}
			make -C libft
			gcc ${CFLAGS} ${BONUS_OBJT} ${LIBFT} -o ${BONUS}

bonus: $(BONUS)

clean:		
			make -C libft fclean
			rm -f ${OBJT}
			rm -f ${BONUS_OBJT}

fclean: 	clean
			rm -f ${NAME} ${BONUS}

re: 		fclean all

py:	all
	python3 python_visualizer.py `ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`

.PHONY: all bonus clean fclean re py