#include "../include/cub3d.h"

void free_mlx(t_mlx *mlx)
{
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
}

int free_stuff(t_cubed *cubed, int err_code)
{
	int	i;

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
	if (cubed->map)
		ft_free_split(cubed->map);
	exit(status);
}