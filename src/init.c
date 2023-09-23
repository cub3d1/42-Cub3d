#include "../include/cub3d.h"

/*	init all struct members to NULL or their value	*/
void	init_mlx_struct(t_mlx *mlx)
{
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->map = NULL;
}