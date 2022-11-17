# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 15:35:22 by alfgarci          #+#    #+#              #
#    Updated: 2022/11/17 23:34:02 by alfgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		=\033[1;31m
GREEN	=\033[1;32m
YELLOW	=\033[1;33m
NC		=\033[0m

SRCS =	src/get_cmd.c \
		src/pipex.c \
		src/here_doc.c \
		src/utils.c \
		src/main.c

OBJS 	=	${SRCS:.c=.o}

INC 	=	includes/

CC	=	cc -Wall -Wextra -Werror

NAME 	=	pipex

.c.o:
	@${CC} -c $< -o ${<:.c=.o} -I ${INC}

${NAME}:	${OBJS}
		@echo "${RED}Compiling...${NC}"
		@make -C ./libft
		@${CC} ${OBJS} -Llibft -lft -o ${NAME}
		@echo "${GREEN}${NAME} READY!${NC}"

all:		${NAME}

clean:
		@make clean -C ./libft
		@rm -f ${OBJS}
		@echo "${YELLOW}OBJS REMOVED!${NC}"

fclean:		clean
		@make fclean -C ./libft
		@rm -f ${NAME}
		@echo "${YELLOW}${NAME} REMOVED!${NC}"

re:		fclean all

.PHONY:	all clean fclean re
