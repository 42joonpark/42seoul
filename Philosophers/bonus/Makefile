CC					= gcc

CFLAGS				= -g -Wall -Werror -Wextra

OPT					= -pthread

NAME				= philo

BONUS				= phio_bonus

INC					= -Iincludes

MAND_SRC			= src/arguments.c \
					  src/init.c \
					  src/print.c \
					  src/process.c \
					  src/run.c \
					  src/utils.c \

MAND_OBJS			= $(MAND_SRC:.c=.o)

MAND_MAIN_SRC		= src/main.c

MAND_MAIN_OBJ		= $(MAND_MAIN_SRC:.c=.o)

.PHONY : all, $(NAME), clean, fclean, re, norm_test

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $< $(INC)
	@echo "\033[32m.\033[0m\c"

all : $(NAME)

$(NAME) : $(MAND_OBJS) $(MAND_MAIN_OBJ)
	@$(CC) $(CFLAGS) -o $@ $(MAND_OBJS) $(MAND_MAIN_OBJ)
	@echo "\033[32m.\033[0m"

clean :
	@rm -rf $(MAND_OBJS) $(MAND_MAIN_OBJ)
	@echo "make clean"

fclean : clean
	@rm -rf $(NAME)
	@echo "make fclean"

re : fclean all
	@echo "make re"

norm_test : $(MAND_SRC) $(MAND_MAIN)
	@echo "\033[32m[norminette check]\033[m"
	@norminette $^
