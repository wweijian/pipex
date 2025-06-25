# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/15 21:46:33 by wjhoe             #+#    #+#              #
#    Updated: 2025/06/22 20:02:33 by wjhoe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

HDRS = includes/
M_HDRS = libft.h pipex.h
M_HDRS := ${addprefix ${HDRS}, ${M_HDRS}}
B_HDRS = libft.h pipex_bonus.h gnl_bonus.h
B_HDRS := ${addprefix ${HDRS}, ${B_HDRS}}

LIB_PATH = libft/
LIBFT = ${LIB_PATH}libft.a

OBJS_PATH = objs/

SRCS_PATH = srcs/
SRCS = main.c \
		check_files.c validate_argument.c init.c exit.c \
		arg_parsing.c commands.c pipe.c error_msg.c
SRCS := ${addprefix ${SRCS_PATH}, ${SRCS}}
OBJS := $(addprefix ${OBJS_PATH}, ${notdir ${SRCS:.c=.o}})

BONUS_PATH = bonus/
B_SRCS = main_bonus.c \
		check_files_bonus.c validate_argument_bonus.c init_bonus.c exit_bonus.c \
		arg_parsing_bonus.c commands_bonus.c pipe_bonus.c error_msg_bonus.c \
		gnl_bonus.c gnl_utils_bonus.c
B_SRCS := ${addprefix ${BONUS_PATH}, ${B_SRCS}}
B_OBJS := $(addprefix ${OBJS_PATH}, ${notdir ${B_SRCS:.c=.o}})


CC = cc
CFLAGS = -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${LIBFT} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -I${HDRS} -L. ${LIBFT} -o ${NAME}

${LIBFT}:
	make -C libft

${OBJS}: ${OBJS_PATH}%.o: ${SRCS_PATH}%.c ${M_HDRS}| ${OBJS_PATH}
	${CC} ${CFLAGS} -c $< -I${HDRS} -o $@

${B_OBJS}: ${OBJS_PATH}%.o: ${BONUS_PATH}%.c ${B_HDRS} | ${OBJS_PATH}
	${CC} ${CFLAGS} -c $< -I${HDRS} -o $@

${OBJS_PATH}:
	mkdir -p ${OBJS_PATH}

bonus: ${LIBFT} ${B_OBJS} ${B_HDRS}
	${CC} ${CFLAGS} ${B_OBJS} -I${HDRS} -L. ${LIBFT} -o ${NAME}

clean:
	make -sC libft clean
	rm -rf ${OBJS_PATH}

fclean: clean
	make -C libft fclean
	rm -rf ${NAME}

re: fclean all

.PHONY: libft all clean fclean bonus