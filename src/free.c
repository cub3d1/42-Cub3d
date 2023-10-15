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

static void	free_mlx_images(t_mlx *mlx)
{
	if (mlx->text_n)
		free_image(mlx, mlx->text_n);
	if (mlx->text_s)
		free_image(mlx, mlx->text_s);
	if (mlx->text_e)
		free_image(mlx, mlx->text_e);
	if (mlx->text_w)
		free_image(mlx, mlx->text_w);
	if (mlx->green_ball)
		free_image(mlx, mlx->green_ball);
	if (mlx->black_ball)
		free_image(mlx, mlx->black_ball);
}

static void	free_canvases(t_mlx *mlx)
{
	if (mlx->surfaces)
	{
		if (mlx->surfaces->map_img)
			free_image(mlx, mlx->surfaces->map_img);
		free(mlx->surfaces);
	}
	if (mlx->automap)
	{
		if (mlx->automap->map_img)
			free_image(mlx, mlx->automap->map_img);
		free(mlx->automap);
	}
	if (mlx->automap_player)
	{
		if (mlx->automap_player->map_img)
			free_image(mlx, mlx->automap_player->map_img);
		free(mlx->automap_player);
	}
	if (mlx->minimap)
	{
		if (mlx->minimap->map_img)
			free_image(mlx, mlx->minimap->map_img);
		free(mlx->minimap);
	}
	if (mlx->minimap_player)
	{
		if (mlx->minimap_player->map_img)
			free_image(mlx, mlx->minimap_player->map_img);
		free(mlx->minimap_player);
	}
}

static void	free_mlx(t_mlx *mlx)
{
	if (mlx)
	{
		if (mlx->win_ptr)
			mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		free_mlx_images(mlx);
		free_canvases(mlx);
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
