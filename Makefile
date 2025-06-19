# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weijian <weijian@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/15 21:46:33 by wjhoe             #+#    #+#              #
#    Updated: 2025/06/19 10:41:13 by weijian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

HDRS = includes

LIB_PATH = libft/
LIBFT = ${LIB_PATH}libft.a

SRCS_PATH = srcs/
SRCS = main.c \
		check_files.c validate_argument.c init.c exit.c paths.c \
		arg_parsing.c commands.c pipe.c gnl_bonus.c gnl_utils_bonus.c
SRCS := ${addprefix ${SRCS_PATH}, ${SRCS}}

OBJS_PATH = objs/
OBJS := $(addprefix ${OBJS_PATH}, ${notdir ${SRCS:.c=.o}})

CC = cc
CFLAGS = -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${LIBFT} ${OBJS} ${HDRS}
	${CC} ${CFLAGS} ${OBJS} -I${HDRS} -L. ${LIBFT} -o ${NAME}

${LIBFT}:
	make -C libft

${OBJS_PATH}%.o: ${SRCS_PATH}%.c ${HDRS} | ${OBJS_PATH}
	${CC} ${CFLAGS} -c $< -I${HDRS} -o $@

${OBJS_PATH}:
	mkdir -p ${OBJS_PATH}

bonus: ${NAME}

clean:
	make -sC libft clean
	rm -rf ${OBJS}

fclean: clean
	make -C libft fclean
	rm -rf ${NAME}

re: fclean all

.PHONY: libft all clean fclean 