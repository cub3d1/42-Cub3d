#include "../include/cub3d.h"

int	window_cross(t_mlx *mlx)
{
	ft_printf_fd(1, "windown cross pressed!\nClosing program...\n");
	free_stuff(mlx);
	return (0);
}