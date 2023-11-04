NAME = get_next_line
CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42

SOURCES = get_next_line.c\
			get_next_line_utils.c\


OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
