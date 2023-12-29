NAME = cub3D # The Cubed!!
CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb -fsanitize=address -Werror=unused-result
RM = rm -f
LIBFT = ./include/libft/libft.a
MINILIBX = ./include/mlx_linux/libmlx_Linux.a
FT_PRINTF_FD = ./include/ft_printf_fd/libftprintf.a
INC = -lXext -lX11 -lm

SRCDIR = ./src/
PARSERDIR = $(SRCDIR)parser/
RENDERDIR = $(SRCDIR)render_next_frame/

COREFILES = main.c hooks.c free.c free_mlx.c init.c init_mlx_struct.c \
				init_pre_render.c map_utils.c exit_err.c load_textures.c

PARSERFILES = parser.c file_content_check.c file_content_check_utils.c \
				map_layout_check.c map_layout_check_utils.c flood_fill.c \
				load_map.c load_colors.c

RENDERFILES = render_next_frame.c show_map2d.c update.c update_utils.c \
				collisions.c pre_render.c raycaster.c pre_render_map2d.c \
				cast_ray.c

SRC = $(COREFILES) $(PARSERFILES) $(RENDERFILES)

FILESC = $(addprefix $(SRCDIR), $(COREFILES)) \
			$(addprefix $(PARSERDIR), $(PARSERFILES)) \
			$(addprefix $(RENDERDIR), $(RENDERFILES)) 

OBJS = $(FILESC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(FT_PRINTF_FD) $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF_FD) $(MINILIBX) $(INC)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Iinclude/mlx_linux -O3 -c -o $@ $<

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
