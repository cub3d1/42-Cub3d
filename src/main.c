#include "../include/cub3d.h"

int main(int argc, char **argv)
{

	t_cubed	cubed;
	/*	ARGUMENT CHECK	*/
	/*	argc check	*/
	if (argc != 2)
	{
		ft_printf_fd(1, "Error\nWrong number of arguments\n");
		return (0);
	}
	/*	init game struct	*/
	init_cubed(&cubed);
	/*	map check	*/
	parser(&cubed, argv[1]);

/*	depois do mapa vemos isto	*/
	/*	init mlx	*/
	cubed.mlx->mlx_ptr = mlx_init();
	cubed.mlx->win_ptr = mlx_new_window(cubed.mlx->mlx_ptr, 500, 250, "Hello world!");

	/* 	Hooks para garantir clean destruction da janela	*/
	mlx_hook(cubed.mlx->win_ptr, ON_KEYPRESS, 1L << 0, keypress_hook, &cubed);
	mlx_hook(cubed.mlx->win_ptr, ON_DESTROY, 1L << 17, window_cross, &cubed);

	mlx_loop(cubed.mlx->mlx_ptr);
	return (0);
	
}