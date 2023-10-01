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
# define WIN_W 1000
# define WIN_H 500

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
# define KEY_TAB 65289

# define SENSITIVITY 0.5f
# define VELOCITY 0.1f

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
# define TEMP_MINIMAP_PLAYER "./textures/temp_player.xpm"

//	should we have a separate struct for the minimap render data?
//	also we need to define player movement and rotation speed
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		ceiling_color[3];
	int		floor_color[3];
	void	*text_n;
	void	*text_s;
	void	*text_e;
	void	*text_w;
	void	*minimap_wall;
	void	*minimap_player;
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
}				t_keys;

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	float	pos_x_array;
	float	pos_y_array;
	float	dir_x;
	float	dir_y;
	float 	angle;
	//	fov? we might need a camera vector for that
}				t_player;

typedef struct s_cubed
{
	char		**map;
	char		**texture_paths;
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
void	init_mlx_struct(t_mlx *mlx);
void	init_player_struct(t_player *player, char **map, int y);

/*		./parser/parser.c */
void 	parser(t_cubed *cubed, char *arg);

/*	./parser/file_content_check.c	*/
bool	textures_ok(int map_fd, t_cubed *cubed);
bool	color_ok(int map_fd, t_cubed *cubed);
bool	map_pos_ok(int map_fd, t_cubed *cubed);

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
void	load_tmp_textures(t_cubed *cubed, char *arg);

/*	./render_next_frame/render_next_frame.c */
int		render_next_frame(t_cubed *cubed);

/*	./render_next_frame/update.c	*/
void	update_angle(t_cubed *cubed);
void	update_player_pos(t_cubed *cubed, t_keys *keys);


/*	./render_next_frame/minimap.c */
void	show_minimap(t_cubed *cubed, int minimap);

/*			free.c		*/
int 	free_stuff(t_cubed *cubed, int err_code);

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