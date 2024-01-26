/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:38:49 by fmouronh          #+#    #+#             */
/*   Updated: 2024/01/15 23:24:02 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_mlx_images(t_mlx *mlx)
{
	if (mlx->text_n)
		free_image(mlx, mlx->text_n);
	if (mlx->text_s)
		free_image(mlx, mlx->text_s);
	if (mlx->text_e)
		free_image(mlx, mlx->text_e);
	if (mlx->text_w)
		free_image(mlx, mlx->text_w);
	if (mlx->automap_player)
		free_image(mlx, mlx->automap_player);
	if (mlx->minimap_player)
		free_image(mlx, mlx->minimap_player);
}

static void	free_lines(unsigned int **buffer_array)
{
	int	i;

	i = 0;
	while (i < WIN_H)
	{
		free(buffer_array[i]);
		i++;
	}
}

void	free_canvases(t_mlx *mlx)
{
	if (mlx->surfaces)
	{
		if (mlx->surfaces->map_img)
			free_image(mlx, mlx->surfaces->map_img);
		if (mlx->surfaces->buffer_array)
		{
			free_lines(mlx->surfaces->buffer_array);
			free(mlx->surfaces->buffer_array);
		}
		free(mlx->surfaces);
	}
	if (mlx->automap)
	{
		if (mlx->automap->map_img)
			free_image(mlx, mlx->automap->map_img);
		free(mlx->automap);
	}
	if (mlx->minimap)
	{
		if (mlx->minimap->map_img)
			free_image(mlx, mlx->minimap->map_img);
		free(mlx->minimap);
	}
}

void	free_image(t_mlx *mlx, t_our_img *img)
{
	if (img->img)
		mlx_destroy_image(mlx->mlx_ptr, img->img);
	free(img);
}
