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

int	keypress_hook(int keycode, t_cubed *cubed)
{
	if (keycode == ESCAPE)
	{
		ft_printf_fd(1, "Escape pressed!\nClosing program...\n");
		free_stuff(cubed, 0);
	}
	// if (keycode == ON_W)
	// {
	// 	cubed->player->pos_x += cubed->player->dir_x * 0.1;
	// 	cubed->player->pos_y += cubed->player->dir_y * 0.1;
	// }
	if (keycode == KEY_TAB)
		cubed->mlx->show_minimap = !cubed->mlx->show_minimap;
	if (keycode == ON_W || keycode == KEY_UP)
		cubed->keys->w = true;
	if (keycode == ON_A || keycode == KEY_LEFT)
		cubed->keys->a = true;
	if (keycode == ON_S || keycode == KEY_DOWN)
		cubed->keys->s = true;
	if (keycode == ON_D || keycode == KEY_RIGHT)
		cubed->keys->d = true;
	return (0);
}

int	keyrelease_hook(int keycode, t_cubed *cubed)
{
	if (keycode == ON_W || keycode == KEY_UP)
		cubed->keys->w = false;
	if (keycode == ON_A || keycode == KEY_LEFT)
		cubed->keys->a = false;
	if (keycode == ON_S || keycode == KEY_DOWN)
		cubed->keys->s = false;
	if (keycode == ON_D || keycode == KEY_RIGHT)
		cubed->keys->d = false;
	return (0);
}