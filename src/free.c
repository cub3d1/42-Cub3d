#include "../include/cub3d.h"

static void	free_mlx(t_mlx *mlx)
{
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	if (mlx)
		free(mlx);
}

static void	free_player(t_player *player)
{
	if (player)
		free(player);
}

int free_stuff(t_cubed *cubed, int err_code)
{
	int	i;

	i = 0;
	free_mlx(cubed->mlx);
	free_player(cubed->player);
	ft_free_split(cubed->map);
	if (err_code >= 0)
		exit(err_code);
	return (0);
}