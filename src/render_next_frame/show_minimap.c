/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:52:05 by ddantas-          #+#    #+#             */
/*   Updated: 2023/09/30 20:52:06 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void show_minimap(t_cubed *cubed, int minimap)
{
	if (minimap++ == 0)
		mlx_clear_window(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr);
	(void)cubed;
}