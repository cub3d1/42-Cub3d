/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:21:14 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/01 08:15:50 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	window_cross(t_cubed *cubed)
{
	ft_printf_fd(1, "windown cross pressed!\nClosing program...\n");
	free_stuff(cubed, 0);
	return (0);
}

static void	read_keystrokes(int keycode, t_cubed *cubed)
{
	if (keycode == KEY_TAB)
		cubed->keys->show_automap = !cubed->keys->show_automap;
	if (keycode == KEY_M)
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
	if (keycode == KEY_I)
		cubed->keys->mouse_movement = !cubed->keys->mouse_movement;
}

int	keypress_hook(int keycode, t_cubed *cubed)
{
	if (keycode == ESCAPE)
	{
		mlx_do_key_autorepeaton(cubed->mlx->mlx_ptr);
		ft_printf_fd(1, "Escape pressed!\nClosing program...\n");
		free_stuff(cubed, 0);
	}
	read_keystrokes(keycode, cubed);
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

// int mouse_hook(int button, int x, int y, t_cubed *cubed)
// {

// 	ft_printf_fd(1, "x = %d | y = %d\n", x, y);

// 	(void)button;
// 	(void)cubed;

// 	return (0);
// }