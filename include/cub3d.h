/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:22:26 by ddantas-          #+#    #+#             */
/*   Updated: 2024/01/29 23:27:29 by hiper            ###   ########.fr       */
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
// # include <float.h>
# include <math.h>

/*		map elements	*/
# define ELEM_NO 0
# define ELEM_SO 1
# define ELEM_EA 2
# define ELEM_WE 3
# define ELEM_C 4
# define ELEM_F 5

/*		window size		*/
# define WIN_W 1360
# define WIN_H 768

/*		keystrokes		*/
# define ON_KEYPRESS 2
# define ON_KEYRELEASE 3
# define ON_DESTROY 17

# define ESCAPE 65307
# define ON_W 119
# define ON_A 97
# define ON_S 115
# define ON_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_M 109
# define KEY_TAB 65289
# define KEY_I 105

/*		player params	*/
# define SENSITIVITY 7.5f
# define VELOCITY 0.3
# define RAY_LENGHT 50

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

/*		map tokens		*/
# define MAP_TKNS "01"
# define PLAYER_TKNS "NSEW"

typedef struct s_ray
{
	char	current_wall;
	int		pos_x;
	int		pos_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	wall_x;
	double	wall_y;
	int		step_x;
	int		step_y;
	char	hit;
	double	wall_dist;
	int		texture_x;
	double	texture_y;
	int		canvas_y;
	int		canvas_x;
	int		canvas_start;
	int		render_h;
	double	render_step;
}				t_ray;

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
	unsigned int	**buffer_array;
	t_our_img		*map_img;
}				t_canvas;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			ceiling_color[3];
	int			floor_color[3];
	int			proj_plane_height;
	t_our_img	*text_n;
	t_our_img	*text_s;
	t_our_img	*text_e;
	t_our_img	*text_w;
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
	bool	mouse_movement;
}				t_keys;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	pos_x_array;
	double	pos_y_array;
	double	dir_x;
	double	dir_y;
	double	dir_x_pos;
	double	dir_y_pos;	
	double	plane_vector_x;
	double	plane_vector_y;

	double	angle;
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
int			window_cross(t_cubed *cubed);
int			keypress_hook(int keycode, t_cubed *cubed);
int			keyrelease_hook(int keycode, t_cubed *cubed);
int			mouse_hook(int button, int x, int y, t_cubed *cubed);

/*			init.c		*/
void		init_cubed(t_cubed *cubed);
void		init_player_struct(t_player *player, char **map, int y);

/*		init_mlx_struct.c	*/
void		init_mlx_struct(t_cubed *cubed);

/*		init_pre_render.c		*/	
void		init_pre_render(t_cubed *cubed);

/*		map_utils.c		*/
float		get_biggest_line(char **map);
float		get_array_size(char **map);

/*	load_textures.c	*/
void		load_textures(t_cubed *cubed, char *arg);

/*		./parser/parser.c */
void		parser(t_cubed *cubed, char *arg);

/*	./parser/file_content_check.c	*/
bool		textures_ok(int map_fd, t_cubed *cubed);
bool		color_ok(int map_fd, t_cubed *cubed);
bool		map_pos_ok(int map_fd);

/*	./parser/file_content_check_utils.c	*/
bool		color_format_ok(char *line);
bool		color_vals_ok(char *line);
bool		map_start(char *line);
bool		elems_ok(int map_fd, t_cubed *cubed);

/*	./parser/file_content_check_utils_2.c	*/
bool		valid_textures(char *line, bool elems[6]);
bool		valid_colors(char *line, bool elems[6]);

/*	./parser/map_layout_check.c	*/
bool		map_tokens_ok(t_cubed *cubed);
bool		player_token_ok(t_cubed *cubed);
bool		layout_enclosed(t_cubed *cubed);

/*	./parser/map_layout_check_utils.c	*/
char		**init_shadow_map(char **map);

/*	./parser/flood_fill.c	*/
void		flood_fill(char **map, int pos_x, int pos_y);
bool		flood_fill_check(char **map);

/*	./parser/file_check.c	*/
bool		textures_ok(int map_fd, t_cubed *cubed);
bool		color_ok(int map_fd, t_cubed *cubed);
int			find_map_offset(t_mlx *mlx, char *arg);

/*	./parser/load_map.c	*/
void		load_map(t_cubed *cubed, char *path);

/*	./parser/load_map_utils.c	*/
int			skip_elems(int map_fd);

/*	./parser/load_colors.c	*/
void		load_colors(t_cubed *cubed, char *path);

/*	./render_next_frame/render_next_frame.c */
int			render_next_frame(t_cubed *cubed);

/*	./render_next_frame/raycaster.c			*/
void		raycaster(t_cubed *cubed);

/*		./render_next_frame/pre_render.c	*/
void		pre_render(t_cubed *cubed);
void		draw_map2d(char **map, t_canvas *map2d);

/* ./render_next_frame/pre_render_map2d.c	*/
void		draw_map2d(char **map, t_canvas *map2d);

/* ./render_next_frame/draw_wall_slice.c	*/
void		pre_render_slice(t_canvas *canvas, t_our_img *texture, t_ray *ray);

/* ./render_next_frame/draw_wall_slice_utils.c	*/
t_our_img	*select_texture(t_ray *ray, t_mlx *mlx);
void		my_mlx_pixel_put(t_our_img *img, int x, int y, int color);

/*	./render_next_frame/update.c	*/
void		update_angle(t_cubed *cubed);
void		update_player_pos(t_cubed *cubed, t_keys *keys, t_player *player);

/*	./render_next_frame/update_utils.c	*/
void		read_mouse_input(t_cubed *cubed);
void		read_key_input(t_cubed *cubed);
void		update_player_dir(t_cubed *cubed, t_player *player);
void		player_walk(t_player *player, t_keys *keys);
void		player_strafe(t_player *player, t_keys *keys);

/*	./render_next_frame/collisions.c	*/
void		check_borders(t_cubed *cubed, t_player *player, t_keys *keys);

/*	./render_next_frame/show_map2d.c */
void		show_map2d(t_cubed *cubed, t_canvas *canvas);
void		show_player(t_cubed *cubed, t_our_img *player, t_canvas *map);

/*	/render_next_frame/cast_ray.c */
void		cast_ray(t_cubed *cubed, t_ray *ray, t_player *player, char **map);

/*	/render_next_frame/cast_ray_utils.c */
void		zero_div_guard(t_ray *ray);
void		init_delta_dist(t_ray *ray);
void		init_step_side(t_ray *ray, t_player *player);

/*			free.c		*/
int			free_stuff(t_cubed *cubed, int err_code);

/*		free_mlx.c	*/
void		free_mlx_images(t_mlx *mlx);
void		free_canvases(t_mlx *mlx);
void		free_image(t_mlx *mlx, t_our_img *img);

/*			exit_err.c 	*/
void		exit_err(t_cubed *cubed, int err_code);

/*		error codes
 *
 *	1 - invalid file format
 *	2 - open error
 *	3 - close error
 *	4 - map load fail
 *	5 - Malloc Failed
 *	6 - Image failed to load
 *
 */

#endif