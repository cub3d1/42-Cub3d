/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:21:14 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/01 09:41:59 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	/*	init mlx	*/
	cubed.mlx->mlx_ptr = mlx_init();

	/*		Temp minimap player init */
	int width;
	int height;
	cubed.mlx->minimap_player =  mlx_xpm_file_to_image(
						cubed.mlx->mlx_ptr, TEMP_MINIMAP_PLAYER, &width, &height);

	cubed.mlx->win_ptr = mlx_new_window(cubed.mlx->mlx_ptr, WIN_W, WIN_H, "Hello world!");

	/* 	Hooks para garantir clean destruction da janela	*/
	mlx_do_key_autorepeatoff(cubed.mlx->mlx_ptr);
	mlx_hook(cubed.mlx->win_ptr, ON_KEYPRESS, 1L << 0, keypress_hook, &cubed);
	mlx_hook(cubed.mlx->win_ptr, ON_KEYRELEASE, 1L << 1, keyrelease_hook, &cubed);
	mlx_hook(cubed.mlx->win_ptr, ON_DESTROY, 1L << 17, window_cross, &cubed);

	// mlx_mouse_hide(cubed.mlx->mlx_ptr, cubed.mlx->win_ptr);
	mlx_mouse_move(cubed.mlx->mlx_ptr, cubed.mlx->win_ptr, WIN_W / 2, WIN_H / 2);
	// mlx_mouse_hook(cubed.mlx->win_ptr, mouse_hook, &cubed);
	mlx_loop_hook(cubed.mlx->mlx_ptr, render_next_frame, &cubed);
	mlx_loop(cubed.mlx->mlx_ptr);
	return (0);
	
}
