# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 02:02:31 by ytouab            #+#    #+#              #
#    Updated: 2022/02/16 06:59:40 by ytouab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

OBJS	= ${SRC:.c=.o}


RM			= rm -f

GCCF		= gcc -Wall -Wextra -Werror

SF			= sorting_functions/sorting.c

OP		=		operations/pa.c \
				operations/pb.c \
				operations/ra.c \
				operations/rb.c \
				operations/rr.c \
				operations/rra.c \
				operations/rrb.c \
				operations/rrr.c \
				operations/sa.c \
				operations/sb.c \
				operations/ss.c \

SRCS		=	srcs/helper_functions.c \
				srcs/parser.c \
				srcs/utils.c \
				srcs/utils2.c \
				srcs/validator.c \


SRC		=	push_swap.c \
			${OP} \
			${SF} \
			${SRCS} \



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
