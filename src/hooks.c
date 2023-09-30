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
	return (0);
}
