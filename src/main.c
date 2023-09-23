#include "../include/cub3d.h"

int main()
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 500, 250, "Hello world!");

	mlx_hook(mlx.win_ptr, ON_DESTROY, 1L << 17, window_cross, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
	
}