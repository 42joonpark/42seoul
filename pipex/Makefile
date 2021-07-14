CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

INCLUDE = -Iincludes

NAME = pipex

SRCS = src/main.c \
	   src/execute_which.c \
	   src/util.c \
	   src/split.c

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
