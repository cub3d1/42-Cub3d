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

# define ON_KEYPRESS 2
# define ON_DESTROY 17

/*		map tokens		*/
# define MAP_TKNS "01"
# define PLAYER_TKNS "NSEW"

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	unsigned char	surface_colors[2][3];
}				t_mlx;

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	//	direction
	//	fov?
}				t_player;


typedef struct s_cubed
{
	char		**map;
	char		**texture_paths;
	t_mlx		*mlx;
	t_player	*player;
	/*
	 *
	 *	needs to store 
	 *		paths to textures
	 *		values of colors
	 *		matrix of map
	 *		player start position
	 *
	 */
}				t_cubed;

/*			hooks.c		 */
int		window_cross(t_cubed *cubed);
int		keypress_hook(int keycode, t_cubed *cubed);

/*			init.c		*/
void	init_mlx_struct(t_mlx *mlx);
void	init_cubed(t_cubed *cubed);

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

/*	./parser/flood_fill.c	*/
void	flood_fill(char **map, int pos_x, int pos_y);
bool	flood_fill_check(char **map);

/*	./parser/file_check.c	*/
bool	textures_ok(int map_fd, t_cubed *cubed);
bool	color_ok(int map_fd, t_cubed *cubed);
int		find_map_offset(t_mlx *mlx, char *arg);

/*	./parser/load_map.c	*/
int		load_map(t_cubed *cubed, char *path);

/*			free.c		*/
int 	free_stuff(t_cubed *cubed, int err_code);
void	abort_init(int status, t_cubed *cubed);

/*			exit_err.c 	*/
void	exit_err(t_cubed *cubed, int err_code);

#endif

/*		error codes
 *
 *	1 - invalid file format
 *	2 - open error
 *	3 - close error
 *	4 - malloc fail
 *
 */