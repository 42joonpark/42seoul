CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = -Iincludes/

NAME = libftprintf.a

SRC = src/ft_printf.c src/utils.c src/handle.c src/t_body.c src/print_c.c src/print_s.c src/print_d.c src/print_u.c src/print_x.c src/print_xx.c src/print_p.c src/print_percentage.c

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(INCLUDE)

$(NAME) : $(OBJECTS)
	ar rs $@ $^

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
