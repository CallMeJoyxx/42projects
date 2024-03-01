NAME = so_long
CC = cc
LIBMLX_DIR = ./mlx42
HEADERS := -I ./include -I $(LIBMLX)/include
CFLAGS = -Wall -Wextra -Werror
LIBMLX = $(LIBMLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit
SOURCES = so_long.c


OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(LIBMLX_DIR)
	@cc -o $(NAME) $(CFLAGS) $(HEADERS) $(SOURCES) $(LIBMLX)


$(LIBMLX_DIR):
	git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX_DIR)
	cd $(LIBMLX_DIR) && cmake -B build && cmake --build build -j4

clean:
	@rm -f $(OBJECTS)
	@rm -rf $(LIBMLX_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all libmlx


