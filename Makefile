# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -Wextra -Werror

# Name of your library
NAME = libftprintf.a

# All your source files
SRCS = ft_printf.c handlers.c hexhelpers.c uhelpers.c

# Corresponding object files
OBJS = $(SRCS:.c=.o)

# Header files
HEADER = handlers.h hexhelpers.h uhelpers.h

# Rule to compile your library
all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean object files
clean:
	make clean -C libft
	rm -f $(OBJS)

# Rule to clean object files and library
fclean: clean
	make fclean -C libft
	rm -f $(NAME)

# Rule to recompile your library
re: fclean all

.PHONY: all clean fclean re
