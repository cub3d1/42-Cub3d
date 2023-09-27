#include "../include/cub3d.h"

int free_stuff(t_mlx *mlx, int err_code)
{
	int	i;

	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	i = 0;
	if (mlx->map)
	{
		while (mlx->map[i])
		{
			free(mlx->map[i]);
			mlx->map[i++] = NULL;
		}
		free(mlx->map);
		mlx->map = NULL;
	}
	if (err_code >= 0)
		exit(err_code);
	return (0);
}