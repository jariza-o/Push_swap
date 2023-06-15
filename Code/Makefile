# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 11:56:41 by jariza-o          #+#    #+#              #
#    Updated: 2023/06/15 19:52:37 by jariza-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		pushswap

SRC =		push_swap.c errors.c numbers.c stacks.c \
			Movements/swap.c Movements/rotate.c Movements/reverse.c Movements/push.c\
			utils.c \

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

.PHONY: all clean fclean re