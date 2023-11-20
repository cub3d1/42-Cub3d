/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:21:14 by fmouronh          #+#    #+#             */
/*   Updated: 2023/09/30 19:21:14 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	free_mlx(t_mlx *mlx)
{
	if (mlx)
	{
		if (mlx->win_ptr)
			mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		free_mlx_images(mlx);
		free_canvases(mlx);
		if (mlx->renderer)
			free_renderer(mlx->renderer);
		if (mlx->mlx_ptr)
		{
			mlx_destroy_display(mlx->mlx_ptr);
			free(mlx->mlx_ptr);
		}
		free(mlx);
	}
}

static void	free_player(t_player *player)
{
	if (player)
		free(player);
}

static void	free_keys(t_keys *keys)
{
	if (keys)
		free(keys);
}

int	free_stuff(t_cubed *cubed, int err_code)
{
	free_mlx(cubed->mlx);
	free_player(cubed->player);
	free_keys(cubed->keys);
	ft_free_split(cubed->map);
	if (err_code >= 0)
		exit(err_code);
	return (0);
}
