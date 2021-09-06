CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

INCLUDE = -Iincludes/

NAME = libftprintf.a

SRC = src/ft_printf.c \
	  src/state_machine.c \
	  src/ft_opt.c \
	  src/utils.c \
	  src/print_c.c \
	  src/print_c_state.c \
	  src/print_s.c \
	  src/print_d.c \
	  src/print_u.c \
	  src/print_x.c \
	  src/print_xx.c \
	  src/print_p.c \
	  src/print_percentage.c \
	  src/main.c

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(INCLUDE)

$(NAME) : $(OBJECTS)
	ar rs $@ $^
	#$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

