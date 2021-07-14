# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 12:11:46 by joonpark          #+#    #+#              #
#    Updated: 2021/07/14 15:36:39 by joonpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

INCLUDE = -Iincludes

NAME = pipex

SRCS = src/main.c \
	   src/basics/init.c \
	   src/exec/exec.c \
	   src/exec/exec_which.c \
	   src/utils/split.c \
	   src/utils/util.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(INCLUDE)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBDIR) $(LIBS) $(OPTION)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
