/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:22:26 by ddantas-          #+#    #+#             */
/*   Updated: 2023/10/01 14:23:31 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/includes/libft.h"
# include "./ft_printf_fd/ft_printf.h"
# include "./mlx_linux/mlx.h"
# include "./mlx_linux/mlx_int.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

/*		window size		*/
# define WIN_W 1360
# define WIN_H 728

/*		keystrokes		*/
# define ESCAPE 65307
# define ON_W 119
# define ON_A 97
# define ON_S 115
# define ON_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_M 109
# define KEY_TAB 65289

# define SENSITIVITY 0.5f
# define VELOCITY 0.1
# define RAY_LENGHT 50

# define ON_KEYPRESS 2
# define ON_KEYRELEASE 3
# define ON_DESTROY 17

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

/*		map tokens		*/
# define MAP_TKNS "01"
# define PLAYER_TKNS "NSEW"

/*		texture			*/
# define TEMP_automap_PLAYER "./textures/temp_player.xpm"
# define GREEN_BALL "./textures/green_ball.xpm"
# define BLACK_BALL "./textures/black_ball.xpm"

typedef struct s_our_img
{
	void	*img;
	char	*addr;
	int		w;
	int		h;
	int		bpp;
	int		line_length;
	int		endian;
}				t_our_img;

typedef struct s_canvas
{
	int				wall_w;
	int				wall_h;
	int				pos_x;
	int				pos_y;
	int				scale;
	t_our_img		*map_img;
	struct s_canvas	*next;
}				t_canvas;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			ceiling_color[3];
	int			floor_color[3];
	t_our_img	*text_n;
	t_our_img	*text_s;
	t_our_img	*text_e;
	t_our_img	*text_w;
	t_our_img	*green_ball;
	t_our_img	*black_ball;
	t_our_img	*automap_player;
	t_our_img	*minimap_player;
	t_canvas	*surfaces;
	t_canvas	*automap;
	t_canvas	*minimap;
}				t_mlx;

typedef struct s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
	bool	show_minimap;
	bool	show_automap;
}				t_keys;

	//	fov? we might need a camera vector for that
typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	float	pos_x_array;
	float	pos_y_array;
	float	dir_x;
	float	dir_y;
	float	dir_x_pos;
	float	dir_y_pos;	
	float	left_plane_x;
	float	left_plane_y;
	float	left_plane_x_pos;
	float	left_plane_y_pos;
	float	right_plane_x;
	float	right_plane_y;
	float	right_plane_x_pos;
	float	right_plane_y_pos;
	float	plane_vector_x;
	float	plane_vector_y;

	float	angle;
}				t_player;

typedef struct s_cubed
{
	char		**map;
	char		**texture_paths;
	int			map_width;
	int			map_height;
	t_mlx		*mlx;
	t_player	*player;
	t_keys		*keys;
}				t_cubed;

/*			hooks.c		 */
int		window_cross(t_cubed *cubed);
int		keypress_hook(int keycode, t_cubed *cubed);
int		keyrelease_hook(int keycode, t_cubed *cubed);
int		mouse_hook(int button, int x, int y, t_cubed *cubed);

/*			init.c		*/
void	init_cubed(t_cubed *cubed);
void	init_player_struct(t_player *player, char **map, int y);

/*		init_mlx_struct.c	*/
void	init_mlx_struct(t_cubed *cubed);

/*		init_canvases.c		*/	
void	init_pre_render(t_cubed *cubed);

/*		pre_render.c	*/
void	draw_ceiling(int *ceiling, t_our_img *canvas);
void	draw_floor(int *floor, t_our_img *canvas);
void	draw_map2d(char **map, t_canvas *map2d);

/*		map_utils.c		*/
float	get_biggest_line(char **map);
float	get_array_size(char **map);

/*		./parser/parser.c */
void	parser(t_cubed *cubed, char *arg);

/*	./parser/file_content_check.c	*/
bool	textures_ok(int map_fd, t_cubed *cubed);
bool	color_ok(int map_fd, t_cubed *cubed);
bool	map_pos_ok(int map_fd);

/*	./parser/file_content_check_utils.c	*/
bool	color_format_ok(char *line);
bool	color_vals_ok(char *line);
bool	map_start(char *line);

/*	./parser/map_layout_check.c	*/
bool	map_tokens_ok(t_cubed *cubed);
bool	player_token_ok(t_cubed *cubed);
bool	layout_enclosed(t_cubed *cubed);

/*	./parser/map_layout_check_utils.c	*/
char	**init_shadow_map(char **map);

/*	./parser/flood_fill.c	*/
void	flood_fill(char **map, int pos_x, int pos_y);
bool	flood_fill_check(char **map);

/*	./parser/file_check.c	*/
bool	textures_ok(int map_fd, t_cubed *cubed);
bool	color_ok(int map_fd, t_cubed *cubed);
int		find_map_offset(t_mlx *mlx, char *arg);

/*	./parser/load_map.c	*/
int		load_map(t_cubed *cubed, char *path);

/*	./parser/load_colors.c	*/
void	load_colors(t_cubed *cubed, char *path);

/*	./src/load_textures.c	*/
void	load_textures(t_cubed *cubed, char *arg);

/*	./src/set_automap_walls.c	*/
void	set_automap_walls(t_cubed *cubed);

/*	./render_next_frame/render_next_frame.c */
int		render_next_frame(t_cubed *cubed);
void	render_whole_frame(t_cubed *cubed);

/*	./render_next_frame/update.c	*/
void	update_angle(t_cubed *cubed);
void	update_player_pos(t_cubed *cubed, t_keys *keys, t_player *player);

/*	./render_next_frame/update_utils.c	*/
void	read_mouse_input(t_cubed *cubed);
void	read_key_input(t_cubed *cubed);
void	update_player_dir(t_cubed *cubed, t_player *player);
void	move_player(t_player *player, t_keys *keys);
void	check_borders(t_player *player);

/*	./render_next_frame/show_map2d.c */
void	show_map2d(t_cubed *cubed, t_canvas *canvas);
void	show_player(t_cubed *cubed, t_our_img *player, t_canvas *map);

/*			free.c		*/
int		free_stuff(t_cubed *cubed, int err_code);

/*		free_textures.c	*/
void	free_image(t_mlx *mlx, t_our_img *img);

/*			exit_err.c 	*/
void	exit_err(t_cubed *cubed, int err_code);

#endif

/*		error codes
 *
 *	1 - invalid file format
 *	2 - open error
 *	3 - close error
 *	4 - map load fail
 *	5 - Malloc Failed
 *	6 - Image failed to load
 */