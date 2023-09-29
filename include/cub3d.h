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
}				t_mlx;

typedef struct s_cubed
{
	char		**texture_paths;
	int			surface_colors[2][3];
	char		**map;
	int			start_pos[2];
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

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	//	direction
	//	fov?
}				t_player;

/*			hooks.c		 */
int		window_cross(t_mlx *mlx);
int		keypress_hook(int keycode, t_mlx *mlx);

/*			init.c		*/
void	init_mlx_struct(t_mlx *mlx);
t_cubed	*init_cubed(void);

/*			free.c		*/
int 	free_stuff(t_mlx *mlx);
void	abort_init(int status, t_cubed *cubed);

/*		./parser/parser.c */
void 	parser(t_cubed *cubed, char *arg);

/*	./parser/file_content_check.c	*/
bool	textures_ok(int map_fd, t_cubed *cubed);
bool	color_ok(int map_fd, t_cubed *cubed);
bool	map_pos_ok(int map_fd);

/*	./parser/file_content_check_utils.c	*/
bool	color_format_ok(char *line);
bool	color_vals_ok(char *line);
bool	map_start(char *line);

/*	./parser/map_layout_check.c	*/
bool	map_tokens_ok(char *path, int offset, t_cubed *cubed);
bool	player_token_ok(char *path, int offset, t_cubed *cubed);
bool	layout_enclosed(char *path, int offset, t_cubed *cubed);

/*	./parser/flood_fill.c	*/
void	flood_fill(char *map, int pos_x, int pos_y);

#endif

/*		error codes
 *
 *	1 - invalid file format
 *	2 - open error
 *	3 - close error
 *	4 - malloc fail
 *
 */