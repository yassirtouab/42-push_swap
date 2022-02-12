# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 02:02:31 by ytouab            #+#    #+#              #
#    Updated: 2022/02/12 18:30:51 by ytouab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

OBJS	= ${SRC:.c=.o}


RM			= rm -f

GCCF		= gcc -Wall -Wextra -Werror

OP			= operations/*.c

SF			= sorting_functions/*.c

SRCS		= srcs/*.c

SRC		=	push_swap.c \
			${OP} \
			${SF} \
			${srcs} \



.c.o:
		${GCCF} -c $< -o ${<:.c=.o}


$(NAME):	${OBJS}
		${GCCF} ${OBJS} -o ${NAME}



all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
