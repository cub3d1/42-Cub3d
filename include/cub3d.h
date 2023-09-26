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

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	unsigned char	**map;
}				t_mlx;

/*			hooks.c		 */
int		window_cross(t_mlx *mlx);
int		keypress_hook(int keycode, t_mlx *mlx);

/*			init.c		*/
void	init_mlx_struct(t_mlx *mlx);

/*			free.c		*/
int 	free_stuff(t_mlx *mlx);

/*		./parser/parser.c */
void 	parser(t_mlx *mlx, char *arg);

/*	./parser/file_check.c	*/
bool	textures_ok(int map_fd, char **line);
bool	color_ok(int map_fd, char **line);
int		find_map_offset(char *arg);
#endif

/*		error codes
 *
 *	1 - invalid file format
 *	2 - open error
 *	3 - close error
 */