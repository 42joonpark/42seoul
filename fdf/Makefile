CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

INCLUDE = -Iminilibx -Iincludes

LIBDIR = -L./minilibx -L./lib

LIBS = -lft -lgnl -lmlx

OPTION = -framework OpenGL -framework AppKit

SRCS = src/main.c \
	   src/init.c \
	   src/map.c \
	   src/get_color.c \
	   src/fatal.c \
	   src/map_fatal.c \
	   src/make_map_arr.c \
	   src/draw.c \
	   src/isometric.c \
	   src/colors.c \
	   src/util.c \
	   src/conversion.c \
	   src/event.c \
	   src/keyboard.c

NAME = result

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o  $@ $(INCLUDE)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBDIR) $(LIBS) $(OPTION)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
