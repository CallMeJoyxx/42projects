NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_printf.c\
			ft_print_char.c\
			ft_print_string.c\
			ft_print_int.c\
			ft_print_hex_up.c\
			ft_print_hex_down.c\
			ft_print_unsigned.c\
			ft_print_ptr.c
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
