NAME = cub3d # The Cubed!!

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
RM = rm -f
LIBFT = ./include/libft/libft.a
MINILIBX = ./include/mlx_linux/libmlx_Linux.a
FT_PRINTF_FD = ./include/ft_printf_fd/libftprintf.a
FILESC = ./src/main.c

OBJS = $(FILESC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF_FD) $(MINILIBX) $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF_FD) $(MINILIBX)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C ./include/libft

$(FT_PRINTF_FD):
	$(MAKE) -C ./include/ft_printf_fd

$(MINILIBX): 
	$(MAKE) -C mlx_linux

clean:
	$(RM) -f $(OBJS)
	$(MAKE) -C include/libft clean
	$(MAKE) -C ./include/ft_printf_fd clean
	
fclean: clean
	$(MAKE) -C include/libft fclean
	$(MAKE) -C ./include/ft_printf_fd fclean
	$(RM) $(NAME)

re: fclean all

# Leak checker without leaks from readline :D
l: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=.ignore_readline --track-origins=yes --log-file="valgrind.txt ./$(NAME)

.PHONY: all clean fclean re bonus l