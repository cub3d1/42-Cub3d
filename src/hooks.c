/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:21:14 by fmouronh          #+#    #+#             */
/*   Updated: 2023/09/30 19:21:14 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	window_cross(t_cubed *cubed)
{
	ft_printf_fd(1, "windown cross pressed!\nClosing program...\n");
	free_stuff(cubed, 0);
	return (0);
}

	// if (keycode == ON_W)
	// {
	// 	cubed->player->pos_x += cubed->player->dir_x * 0.1;
	// 	cubed->player->pos_y += cubed->player->dir_y * 0.1;
	// }

int	keypress_hook(int keycode, t_cubed *cubed)
{
	if (keycode == ESCAPE)
	{
		ft_printf_fd(1, "Escape pressed!\nClosing program...\n");
		free_stuff(cubed, 0);
	}
	if (keycode == KEY_TAB)
		cubed->keys->show_minimap = !cubed->keys->show_minimap;
	if (keycode == ON_W)
		cubed->keys->w = true;
	if (keycode == ON_A)
		cubed->keys->a = true;
	if (keycode == ON_S)
		cubed->keys->s = true;
	if (keycode == ON_D)
		cubed->keys->d = true;
	if (keycode == KEY_LEFT)
		cubed->keys->left = true;
	if (keycode == KEY_RIGHT)
		cubed->keys->right = true;
	return (0);
}

int	keyrelease_hook(int keycode, t_cubed *cubed)
{
	if (keycode == ON_W)
		cubed->keys->w = false;
	if (keycode == ON_A)
		cubed->keys->a = false;
	if (keycode == ON_S)
		cubed->keys->s = false;
	if (keycode == ON_D)
		cubed->keys->d = false;
	if (keycode == KEY_LEFT)
		cubed->keys->left = false;
	if (keycode == KEY_RIGHT)
		cubed->keys->right = false;
	return (0);
}

int mouse_hook(int button, int x, int y, t_cubed *cubed)
{

	ft_printf_fd(1, "x = %d | y = %d\n", x, y);

	(void)button;
	(void)cubed;
	
	return (0);
}