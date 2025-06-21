# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/15 21:46:33 by wjhoe             #+#    #+#              #
#    Updated: 2025/06/19 22:06:58 by wjhoe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

HDRS = includes

LIB_PATH = libft/
LIBFT = ${LIB_PATH}libft.a

OBJS_PATH = objs/

SRCS_PATH = srcs/
SRCS = main.c \
		check_files.c validate_argument.c init.c exit.c \
		arg_parsing.c commands.c pipe.c gnl.c gnl_utils.c
SRCS := ${addprefix ${SRCS_PATH}, ${SRCS}}
OBJS := $(addprefix ${OBJS_PATH}, ${notdir ${SRCS:.c=.o}})

BONUS_PATH = bonus/
B_SRCS = main_bonus.c \
		check_files_bonus.c validate_argument_bonus.c init_bonus.c exit_bonus.c \
		arg_parsing_bonus.c commands_bonus.c pipe_bonus.c gnl_bonus.c gnl_utils_bonus.c
B_SRCS := ${addprefix ${BONUS_PATH}, ${B_SRCS}}
B_OBJS := $(addprefix ${OBJS_PATH}, ${notdir ${B_SRCS:.c=.o}})


CC = cc
CFLAGS = -Wall -Werror -Wextra -g -O0

all: ${NAME}

${NAME}: ${LIBFT} ${OBJS} ${HDRS}
	${CC} ${CFLAGS} ${OBJS} -I${HDRS} -L. ${LIBFT} -o ${NAME}

${LIBFT}:
	make -C libft

${OBJS}: ${OBJS_PATH}%.o: ${SRCS_PATH}%.c ${HDRS} | ${OBJS_PATH}
	${CC} ${CFLAGS} -c $< -I${HDRS} -o $@

${B_OBJS}: ${OBJS_PATH}%.o: ${BONUS_PATH}%.c ${HDRS} | ${OBJS_PATH}
	${CC} ${CFLAGS} -c $< -I${HDRS} -o $@

${OBJS_PATH}:
	mkdir -p ${OBJS_PATH}

bonus: ${LIBFT} ${B_OBJS} ${HDRS}
	${CC} ${CFLAGS} ${B_OBJS} -I${HDRS} -L. ${LIBFT} -o ${NAME}

clean:
	make -sC libft clean
	rm -rf ${OBJS}
	rm -rf ${B_OBJS}

fclean: clean
	make -C libft fclean
	rm -rf ${NAME}

re: fclean all

.PHONY: libft all clean fclean bonus