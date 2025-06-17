# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weijian <weijian@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/15 21:46:33 by wjhoe             #+#    #+#              #
#    Updated: 2025/06/16 22:22:20 by weijian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INPUT = input
OUTPUT = output

all: libft ${INPUT} ${OUTPUT}
	clear
	cc srcs/*.c gnl/*.c -I includes -L. libft/libft.a -o pipex
	./pipex input true true true output

${INPUT}:
	cc input.c -o input

${OUTPUT}:
	cc output.c -o output

libft:
	make -sC libft

clean:
	make -C libft clean

flcean:
	rm pipex
	make -C libft fclean

.PHONY: libft