#include "../include/cub3d.h"

int	window_cross(t_mlx *mlx)
{
	ft_printf_fd(1, "windown cross pressed!\nClosing program...\n");
	free_stuff(mlx, 0);
	return (0);
}

int	keypress_hook(int keycode, t_mlx *mlx)
{
	if (keycode == ESCAPE)
	{
		ft_printf_fd(1, "Escape pressed!\nClosing program...\n");
		free_stuff(mlx, 0);
	}
	return (0);
}