# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 02:02:31 by ytouab            #+#    #+#              #
#    Updated: 2022/02/13 01:51:22 by ytouab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

OBJS	= ${SRC:%.c=%.o}


RM			= rm -f

GCCF		= gcc -Wall -Wextra -Werror

OP			= operations/*.c

SF			= sorting_functions/pa.c \
				sorting_functions/pb.c \
				sorting_functions/ra.c \
				sorting_functions/rb.c \
				sorting_functions/rr.c \
				sorting_functions/rra.c \
				sorting_functions/rrb.c \
				sorting_functions/rrb.c \
				sorting_functions/rrr.c \
				sorting_functions/sa.c \
				sorting_functions/sb.c \
				sorting_functions/ss.c \

SRCS		= srcs/helper_functions.c \
				srcs/parser.c \
				srcs/utils.c \
				srcs/utils2.c \
				validator.c \


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
