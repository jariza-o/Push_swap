# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 11:56:41 by jariza-o          #+#    #+#              #
#    Updated: 2023/06/19 19:54:04 by jariza-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		push_swap

BONUS =		checker

SRC =		push_swap.c errors.c numbers.c stacks.c algorithms.c\
			Movements/swap.c Movements/rotate.c Movements/reverse.c Movements/push.c Movements/algorithms_movements.c\
			algorithms_2.c algorithms_3.c stacks_2.c utils.c \

OBJT =		$(SRC:.c=.o)

SRCBONUS =	checker.c stacks_2.c numbers.c errors.c stacks.c algorithms_2.c \
			Movements/swap.c Movements/rotate.c Movements/reverse.c \
			Movements_checker/swap.c Movements_checker/rotate.c Movements_checker/reverse.c Movements_checker/push.c \
			utils.c \

BONUS_OBJT =	$(SRCBONUS:.c=.o)

CFLAGS =	-Wall -Werror -Wextra

LIBFT =		libft/libft.a

GREEN		=		\033[0;32m
RED			=		\033[0;31m
END			=		\033[0m

.c.o:
		gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME): ${OBJT}
			make -C libft
			gcc ${CFLAGS} ${OBJT} ${LIBFT} -o ${NAME}
			@echo "$(GREEN)Push_swap Ready"

$(BONUS): ${BONUS_OBJT}
			make -C libft
			gcc ${CFLAGS} ${BONUS_OBJT} ${LIBFT} -o ${BONUS}
			@echo "$(GREEN)Checker ready"

bonus: $(BONUS)

clean:		
			@rm -f ${OBJT}
			@rm -f ${BONUS_OBJT}
			@echo "$(RED)Compiled objects have been removed"

fclean: 	clean
			@rm -f ${NAME} ${BONUS}
			@make fclean -s -C libft
			@echo "$(RED)Executables have been removed"

re: 		fclean all

py:	all
	python3 python_visualizer.py `ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`

.PHONY: all bonus clean fclean re py