#include "../include/cub3d.h"

int main(int argc, char **argv)
{
	t_mlx	mlx;
	t_cubed	*cubed;

	/*	ARGUMENT CHECK	*/
	/*	argc check	*/
	if (argc != 2)
	{
		ft_printf_fd(1, "Error\nWrong number of arguments\n");
		return (0);
	}
	/*	init game struct	*/
	cubed = init_cubed();
	if (!cubed)
		exit(4);
	/*	map check	*/
	parser(cubed, argv[1]);
	/*	init struct	*/
	init_mlx_struct(&mlx);
	/*	init mlx	*/
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 500, 250, "Hello world!");

	/* 	Hooks para garantir clean destruction da janela	*/
	mlx_hook(mlx.win_ptr, ON_KEYPRESS, 1L << 0, keypress_hook, &mlx);
	mlx_hook(mlx.win_ptr, ON_DESTROY, 1L << 17, window_cross, &mlx);

	mlx_loop(mlx.mlx_ptr);
	return (0);
	
}