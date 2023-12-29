/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:22:26 by ddantas-          #+#    #+#             */
/*   Updated: 2023/10/27 19:35:53 by hiper            ###   ########.fr       */
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
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_M 109
# define KEY_TAB 65289

# define FOV 66

/*		player params	*/
# define SENSITIVITY 0.8f
# define VELOCITY 0.1
# define RAY_LENGHT 50

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

/*		minimap scale	*/
# define MINIMAP_SCALE 4
# define MAP_PLAYER_SCALE 8

/*		map tokens		*/
# define MAP_TKNS "01"
# define PLAYER_TKNS "NSEW"

/*		temp textures	*/
# define TEMP_AUTOMAP_PLAYER "./textures/temp_player.xpm"
# define GREEN_BALL "./textures/green_ball.xpm"
# define BLACK_BALL "./textures/black_ball.xpm"

typedef struct s_rwf
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	deltaDistX;
	double	deltaDistY;
	double	sideDistX;
	double	sideDistY;
	double	perpWallDist;
	double	mapX;
	double	mapY;
	int		stepX;
	int		stepY;
	int		side;
	int		lineHeight;
	int		hit;
}			t_rwf;

/*	PUT RAYCASTER DATA HERE	*/
typedef struct s_ray
{
	//	== player pos
	double	start_x;
	double	start_y;

	//	init_ray_dir();
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	//	cast_ray();
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	wall_x;
	double	wall_y;
	char	hit;	//	n or s or e or w

	//	get_dist();
	double	perp_x;
	double	perp_y;
	double	wall_dist;

	//	pre render()
	int		canvas_y;
	int		canvas_x;
	int		canvas_start;
	int		render_h;

/*
	int		tex_x;
	float	render_h;

	int		start_y;
	int		end_y;
	int		canvas_y;
	int		texture_y;
	int		step;
*/
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

	/*	DELET DIS FFS	*/	
	t_our_img	*black_ball;
	t_our_img	*green_ball;
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
	double	left_plane_x;
	double	left_plane_y;
	double	left_plane_x_pos;
	double	left_plane_y_pos;
	double	right_plane_x;
	double	right_plane_y;
	double	right_plane_x_pos;
	double	right_plane_y_pos;
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

/*	set_automap_walls.c	*/
//void	set_automap_walls(t_cubed *cubed);

/*			free.c		*/
int			free_stuff(t_cubed *cubed, int err_code);

/*		free_mlx.c	*/
void		free_mlx_images(t_mlx *mlx);
void		free_canvases(t_mlx *mlx);
void		free_image(t_mlx *mlx, t_our_img *img);

/*			exit_err.c 	*/
void		exit_err(t_cubed *cubed, int err_code);

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
int			load_map(t_cubed *cubed, char *path);

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
/*
t_our_img	select_texture(t_ray *ray, t_mlx *mlx);
void		set_render_height(t_ray *ray, t_canvas *canvas);
int			find_texture_x(t_ray *ray, t_our_img *texture);
void		pre_render_slice(t_ray *ray, t_our_img *texture, t_canvas *canvas);
*/
/* ./render_next_frame/draw_wall_slice_utils.c	*/
/*
void		interpolate_texture(t_render *ray, t_canvas *surfaces, \
								t_our_img *texture, float ratio);
void		copy_to_canvas(t_render *ray, t_canvas *surfaces, \
							t_our_img *texture);
void		skip_texture_pixels(t_render *ray, t_canvas *surfaces, \
						t_our_img *texture, float ratio);
*/

/* ./render_next_frame/pre_render_walls_utils.c	*/
/*
t_our_img	*select_texture(t_player *player, t_mlx *mlx, t_render *ray);
int			find_tex_x(t_render *ray, t_our_img *texture);
float		find_render_h(t_mlx *mlx, t_render *ray, \
							t_our_img *texture, t_player *player);
*/
/*	./render_next_frame/update.c	*/
void		update_angle(t_cubed *cubed);
void		update_player_pos(t_cubed *cubed, t_keys *keys, t_player *player);

/*	./render_next_frame/update_utils.c	*/
void		read_mouse_input(t_cubed *cubed);
void		read_key_input(t_cubed *cubed);
void		update_player_dir(t_cubed *cubed, t_player *player);
void		move_player(t_player *player, t_keys *keys);

/*	./render_next_frame/collisions.c	*/
void		check_borders(t_cubed *cubed, t_player *player, \
	float prev_x, float prev_y);

/*	./render_next_frame/show_map2d.c */
void		show_map2d(t_cubed *cubed, t_canvas *canvas);
void		show_player(t_cubed *cubed, t_our_img *player, t_canvas *map);

/*	/render_next_frame cast_ray */
void	cast_ray(t_ray *ray, char **map);

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