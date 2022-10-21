# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 15:35:22 by alfgarci          #+#    #+#              #
#    Updated: 2022/10/21 17:21:36 by alfgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	src/get_cmd.c \
		src/pipex.c \
		src/here_doc.c \
		src/main.c

OBJS 	=	${SRCS:.c=.o}

INC 	=	includes/

CC	=	cc -Wall -Wextra -Werror


NAME 	=	pipex

.c.o:
	${CC} -c $< -o ${<:.c=.o} -I ${INC}

${NAME}:	${OBJS}
		@make re -C ./libft
		${CC} ${OBJS} -Llibft -lft -o ${NAME}

all:		${NAME}

clean:
		@make clean -C ./libft
		rm -f ${OBJS}

fclean:		clean
		@make fclean -C ./libft
		rm -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
