# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 02:02:31 by ytouab            #+#    #+#              #
#    Updated: 2022/02/19 20:56:28 by ytouab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap

OBJS		= ${SRC:.c=.o}

WHITE		=	"\033[0m"
RED			=	"\033[0;31m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[0;33m"

RM			=	rm -f

GCCF		=	gcc -Wall -Wextra -Werror

SF			=	sorting_functions/sorting.c \
				sorting_functions/sorting_utils.c \
				sorting_functions/sorting_utils2.c

OP			=	operations/pa.c \
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


SRC			=	push_swap.c \
				${OP} \
				${SF} \
				${SRCS} \



.c.o:
		@${GCCF} -c $< -o ${<:.c=.o}


$(NAME):	${OBJS}
		@${GCCF} ${OBJS} -o ${NAME}
		@echo ${GREEN}"Compilation Done ✅"



all:	${NAME}

clean:
		@${RM} ${OBJS}
		@echo ${RED}"Object Files Deleted ✅"${WHITE}

fclean:	clean
		@${RM} ${NAME}
		@echo ${RED}"Executable File Deleted ✅"${WHITE}

re:		fclean all

