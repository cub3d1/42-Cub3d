/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:04:41 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/12 17:04:58 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_image(t_mlx *mlx, t_our_img *img)
{
	if (img->img)
		mlx_destroy_image(mlx->mlx_ptr, img->img);
	free(img);
}
