#include "../include/cub3d.h"

int free_stuff(t_cubed *cubed, int err_code)
{
	int	i;

	if (cubed->mlx->win_ptr)
		mlx_destroy_window(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr);
	if (cubed->mlx->mlx_ptr)
	{
		mlx_destroy_display(cubed->mlx->mlx_ptr);
		free(cubed->mlx->mlx_ptr);
	}
	i = 0;
	if (cubed->map)
	{
		while (cubed->map[i])
		{
			free(cubed->map[i]);
			cubed->map[i++] = NULL;
		}
		free(cubed->map);
		cubed->map = NULL;
	}
	if (err_code >= 0)
		exit(err_code);
	return (0);
}

void	abort_init(int status, t_cubed *cubed)
{
	if (cubed)
	{
		if (cubed->texture_paths)
			ft_free_split(cubed->texture_paths);
		if (cubed->map)
			ft_free_split(cubed->map);
	}
	exit(status);
}