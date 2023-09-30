NAME = cub3d # The Cubed!!
CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb -fsanitize=address
RM = rm -f
LIBFT = ./include/libft/libft.a
MINILIBX = ./include/mlx_linux/libmlx_Linux.a
FT_PRINTF_FD = ./include/ft_printf_fd/libftprintf.a
INC = -lXext -lX11

SRCDIR = ./src/
PARSERDIR = $(SRCDIR)parser/
RENDERDIR = $(SRCDIR)render_next_frame/

COREFILES = main.c hooks.c free.c init.c exit_err.c
PARSERFILES = parser.c file_content_check.c file_content_check_utils.c map_layout_check.c flood_fill.c load_map.c
RENDERFILES = render_next_frame.c
SRC = $(COREFILES) $(PARSERFILES) $(RENDERFILES)

FILESC = $(addprefix $(SRCDIR), $(COREFILES)) \
			$(addprefix $(PARSERDIR), $(PARSERFILES)) \
			$(addprefix $(RENDERDIR), $(RENDERFILES)) 

OBJS = $(SRC:.c=.o)
	

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(FT_PRINTF_FD) $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF_FD) $(MINILIBX) $(INC)

$(OBJS): $(FILESC)
	$(CC) $(CFLAGS) -c $(FILESC)


$(LIBFT):
	$(MAKE) -C ./include/libft

$(FT_PRINTF_FD):
	$(MAKE) -C ./include/ft_printf_fd

$(MINILIBX): 
	$(MAKE) -C ./include/mlx_linux

clean:
	$(RM) -f $(OBJS)
	$(MAKE) -C ./include/libft clean
	$(MAKE) -C ./include/ft_printf_fd clean
	$(MAKE) -C ./include/mlx_linux clean
	
fclean: clean
	$(MAKE) -C include/libft fclean
	$(MAKE) -C ./include/ft_printf_fd fclean
	$(MAKE) -C ./include/mlx_linux clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
