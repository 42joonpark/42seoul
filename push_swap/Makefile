# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/22 16:58:49 by joonpark          #+#    #+#              #
#    Updated: 2021/09/04 15:46:33 by joonpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC						= gcc

CFLAGS					= -g -Wall -Wextra -Werror

DEBUG					= false

NAME					= push_swap

CHECK_NAME				= checker

DNAME 					= debug

INC 					= -Iincludes

SRC 					= src/algorithm/insert_sort.c \
						src/algorithm/merge_sort.c \
						src/body/body.c \
						src/errors/error.c \
						src/errors/fatal.c \
						src/init/check.c \
						src/init/check_util.c \
						src/instructions/push.c \
						src/instructions/rotate.c \
						src/instructions/rrotate.c \
						src/instructions/swap.c \
						src/stack/stack.c \
						src/stack/stack_util.c \
						src/stack/node.c \
						src/stack/info.c \
						src/stack/info_stack.c \
						src/utils/duplicate.c \
						src/utils/js_split.c \
						src/utils/js_strlen.c  \
						src/utils/js_strnbr.c \
						src/push_swap/push_swap.c \
						src/push_swap/sort.c \
						src/push_swap/sort_small.c \
						src/push_swap/find_pivot.c \
						src/push_swap/find_median.c \
						src/push_swap/a_to_b.c \
						src/push_swap/b_to_a.c

CHECK_SRC 				= src/algorithm/insert_sort.c \
						src/algorithm/merge_sort.c \
						src/body/body.c \
						src/errors/error.c \
						src/errors/fatal.c \
						src/init/check.c \
						src/init/check_util.c \
						src/instructions/push.c \
						src/instructions/rotate.c \
						src/instructions/rrotate.c \
						src/instructions/swap.c \
						src/stack/stack.c \
						src/stack/stack_util.c \
						src/stack/node.c \
						src/stack/info.c \
						src/stack/info_stack.c \
						src/utils/duplicate.c \
						src/utils/js_split.c \
						src/utils/js_strlen.c  \
						src/utils/js_strnbr.c \
						src/utils/js_strchr.c \
						src/utils/js_strcmp.c \
						src/utils/js_strjoin.c \
						src/utils/js_strndup.c \
						src/utils/get_line.c \
						src/checker/checker_program.c \
						src/checker/checker_program_helper.c

OBJS					= $(SRC:.c=.o)

CHECK_OBJS				= $(CHECK_SRC:.c=.o)

MAIN					= src/main.c

CHECKER					= src/checker/checker.c

MAIN_OBJ				= $(MAIN:.c=.o)

CHECK_MAIN_OBJ			= $(CHECKER:.c=.o)

ifeq ($(DEBUG), false)
	CFLAGS	= -g -Wall -Wextra -Werror
else ifeq ($(DEBUG), true)
	CFLAGS	= -g3 -fsanitize=address -Wall -Wextra -Werror
	NAME	= $(DNAME)
else
$(info ***** Wrong BEBUG option ***** )
endif

.PHONY : all, $(NAME), clean, fclean, re, norm_test

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $< $(INC)
	@echo "\033[32m.\033[0m\c"

all : $(NAME)

bonus : $(CHECK_NAME)

$(CHECK_NAME) : $(CHECK_OBJS) $(CHECK_MAIN_OBJ)
	@$(CC) $(CFLAGS) -o $@ $(CHECK_MAIN_OBJ) $(CHECK_OBJS)
	@echo "\033[32m.\033[0m"

$(NAME) : $(MAIN_OBJ) $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(MAIN_OBJ) $(OBJS)
	@echo "\033[32m.\033[0m"

clean :
	@rm -rf $(MAIN_OBJ) $(OBJS)
	@rm -rf $(CHECK_MAIN_OBJ) $(CHECK_OBJS)
	@echo "make clean"

fclean : clean
	@rm -rf $(NAME) $(DNAME)
	@rm -rf $(CHECK_NAME)
	@echo "make fclean"

re : fclean all
	@echo "make re"

norm_test : $(SRC) $(CHECK_SRC) $(MAIN) $(CHECKER)
	@echo "\033[32m[norminette check]\033[m"
	@norminette $^
