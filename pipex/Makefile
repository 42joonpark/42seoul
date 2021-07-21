# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 00:16:11 by joonpark          #+#    #+#              #
#    Updated: 2021/07/21 11:46:39 by joonpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:= gcc

INC			:= -Iincludes
LIBS 		= 
CFLAGS		:= -g -Wall -Wextra -Werror

SRCS		:= src/basics/main_functions.c \
	   		src/basics/init.c \
	   		src/basics/fatal.c \
	   		src/basics/free.c \
	   		src/basics/heredoc.c \
	   		src/exec/exec.c \
	   		src/exec/exec_which.c \
	   		src/utils/split.c \
	   		src/utils/util.c \
	   		src/utils/get_line.c \
	   		src/utils/ft_strndup.c \
			src/utils/check_file.c
OBJS		= $(SRCS:.c=.o)

MAND_SRC	:= src/main.c

MAND_OBJ	= $(MAND_SRC:.c=.o)

BNS_SRC		:= src/main_bonus.c

BNS_OBJ		= $(BNS_SRC:.c=.o)

NAME		:= pipex

# colors
RED			:= \033[31m
GREEN 		:= \033[32m
YELLOW 		:= \033[33m
BLUE 		:= \033[34m
MAGENTA		:= \033[35m
CYAN		:= \033[36m
WHITE		:= \033[37m
PINK		:= \033[38;5;201m
OBJS_DOT	:= \033[38;5;201m\033[48;5;252m\033[1m\033[3m
MENT		:= \033[38;5;191m\033[1m
RE_MENT		:= \033[38;5;63m\033[1m
RESET		:= \033[0m

.PHONY		:= all ment_re $(NAME) bonus clean fclean re

%.o : %.c
	@$(CC) -c $(CFLAGS) -o $@ $< $(INC)
	@echo "$(OBJS_DOT).$(RESET)\c"

all : $(NAME)

ment_re :
	@echo "$(RE_MENT)[make re]$(RESET)"

$(NAME) : $(OBJS) $(MAND_OBJ)
	@$(CC) -o $@ $(OBJS) $(MAND_OBJ)
	@echo "\n$(GREEN)object files were created$(RESET)"
	@echo "$(GREEN)$(NAME) was created$(RESET)"

bonus : $(OBJS) $(BNS_OBJ)
	@$(CC) -o $(NAME) $(OBJS) $(BNS_OBJ)
	@echo "\n$(GREEN)bonus object files were created$(RESET)"
	@echo "$(GREEN)$(NAME) was created$(RESET)"

clean :
	@rm -rf $(OBJS) $(MAND_OBJ) $(BNS_OBJ)
	@echo "$(MENT)[Removing object files]"
	@echo "$(MAGENTA)$(OBJS)$(RESET)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(MENT)[Removing $(NAME)]$(RESET)"
	@echo "$(NAME):$(MAGENTA) deleted$(RESET)"

re : ment_re fclean all
	@echo "$(RE_MENT)[make re done.]$(RESET)"

norm_test :
	@echo "$(MENT)[Norminette test]$(CYAN)"
	@find ./src -name "*.c" -exec norminette {} \;
	@find ./includes -name "*.h" -exec norminette {} \;
