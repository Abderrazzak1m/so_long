NAME = so_long

HEADER = so_long.h\
		gnl/get_next_line.h\
		libft/libft.h\
		printf/ft_printf.h
	
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

PRINTF_DIR = printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS = so_long.c \
		objet.c \
		generate_map.c \
		check_map.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		get_assetes.c \
		game_utils.c \
		move.c \
		exit.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT_LIB) $(PRINTF_LIB) $(HEADER) 
	$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFT_LIB) $(PRINTF_LIB) $(OBJS) -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)
$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_LIB) $(PRINTF_LIB)

re: fclean all

.PHONY: all clean fclean re bonus