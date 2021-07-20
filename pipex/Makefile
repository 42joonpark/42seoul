# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 00:16:11 by joonpark          #+#    #+#              #
#    Updated: 2021/07/20 11:24:25 by joonpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

INC = -Iincludes
LIBS = 
CFLAGS = -g -Wall -Wextra -Werror

SRCS = src/main_bonus.c \
	   src/basics/main_functions.c \
	   src/basics/init.c \
	   src/basics/fatal.c \
	   src/basics/free.c \
	   src/basics/heredoc.c \
	   src/exec/exec.c \
	   src/exec/exec_which.c \
	   src/utils/split.c \
	   src/utils/util.c \
	   src/utils/get_line.c \
	   src/utils/ft_strndup.c
OBJS = $(SRCS:.c=.o)

NAME = pipex

# colors
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
PINK = \033[38;5;201m
OBJS_DOT = \033[38;5;201m\033[48;5;252m\033[1m\033[3m
MENT = \033[38;5;191m\033[1m
RE_MENT = \033[38;5;63m\033[1m
RESET = \033[0m

%.o : %.c
	@$(CC) -c $(CFLAGS) -o $@ $< $(INC)
	@echo "$(OBJS_DOT).$(RESET)\c"

all : $(NAME)

ment_re :
	@echo "$(RE_MENT)[make re]$(RESET)"

$(NAME) : $(OBJS)
	@$(CC) -o $@ $(OBJS)
	@echo "\n$(GREEN)object files were created$(RESET)"
	@echo "$(GREEN)$(NAME) was created$(RESET)"

clean :
	@rm -rf $(OBJS)
	@echo "$(MENT)[Removing object files]"
	@echo "$(MAGENTA)$(OBJS)$(RESET)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(MENT)[Removing $(NAME)]$(RESET)"
	@echo "$(NAME):$(MAGENTA) deleted$(RESET)"

re : ment_re fclean all
	@echo "$(RE_MENT)[make re done.]$(RESET)"
