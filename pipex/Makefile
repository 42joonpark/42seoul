# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 12:11:46 by joonpark          #+#    #+#              #
#    Updated: 2021/07/17 18:06:46 by joonpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = -Iincludes

NAME = pipex

SRCS = src/main_bonus.c \
	   src/basics/main_functions.c \
	   src/basics/init.c \
	   src/basics/fatal.c \
	   src/basics/free.c \
	   src/exec/exec.c \
	   src/exec/exec_which.c \
	   src/utils/split.c \
	   src/utils/util.c \
	   src/utils/get_line.c \
	   src/utils/ft_strndup.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(INCLUDE)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
