#include "../include/cub3d.h"

int	window_cross(t_cubed *cubed)
{
	ft_printf_fd(1, "windown cross pressed!\nClosing program...\n");
	free_stuff(cubed, 0);
	return (0);
}

int	keypress_hook(int keycode, t_cubed *cubed)
{
	if (keycode == ESCAPE)
	{
		ft_printf_fd(1, "Escape pressed!\nClosing program...\n");
		free_stuff(cubed, 0);
	}
	// if (keycode == ON_W)
	// {
	// 	cubed->player->pos_x += cubed->player->dir_x * 0.1;
	// 	cubed->player->pos_y += cubed->player->dir_y * 0.1;
	// }
	if (keycode == KEY_TAB)
		cubed->mlx->show_minimap = !cubed->mlx->show_minimap;
	return (0);
}