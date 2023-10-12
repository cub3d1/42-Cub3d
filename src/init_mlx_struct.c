/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:16:37 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/12 17:17:13 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_img_struct(t_our_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = -1;
	img->endian = -1;
	img->h = -1;
	img->line_length = -1;
	img->w = -1;
}

void	init_mlx_struct(t_cubed *cubed)
{
	t_mlx	*mlx;

	mlx = cubed->mlx;
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->text_n = malloc(sizeof(t_our_img));
	mlx->text_s = malloc(sizeof(t_our_img));
	mlx->text_e = malloc(sizeof(t_our_img));
	mlx->text_w = malloc(sizeof(t_our_img));
	mlx->green_ball = malloc(sizeof(t_our_img));
	mlx->black_ball = malloc(sizeof(t_our_img));
	mlx->minimap_player = malloc(sizeof(t_our_img));
	mlx->minimap_wall = malloc(sizeof(t_our_img));
	if (!mlx->text_n || !mlx->text_s || !mlx->text_e || !mlx->text_w
		|| !mlx->minimap_player || !mlx->minimap_wall || !mlx->black_ball
		|| !mlx->green_ball)
		exit_err(cubed, 5);
	init_img_struct(mlx->text_n);
	init_img_struct(mlx->text_s);
	init_img_struct(mlx->text_e);
	init_img_struct(mlx->text_w);
	init_img_struct(mlx->green_ball);
	init_img_struct(mlx->black_ball);
	init_img_struct(mlx->minimap_player);
	init_img_struct(mlx->minimap_wall);
}
