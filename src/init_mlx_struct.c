/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:16:37 by fmouronh          #+#    #+#             */
/*   Updated: 2024/01/15 23:24:36 by hiper            ###   ########.fr       */
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

static void	malloc_canvas_structs(t_mlx *mlx, t_cubed *cubed)
{
	mlx->surfaces = malloc(sizeof(t_canvas));
	mlx->automap = malloc(sizeof(t_canvas));
	mlx->minimap = malloc(sizeof(t_canvas));
	if (mlx->surfaces && mlx->automap && mlx->minimap)
	{
		mlx->surfaces->map_img = malloc(sizeof(t_our_img));
		mlx->automap->map_img = malloc(sizeof(t_our_img));
		mlx->minimap->map_img = malloc(sizeof(t_our_img));
	}
	if (!mlx->surfaces || !mlx->surfaces->map_img \
		|| !mlx->automap || !mlx->minimap \
		|| !mlx->automap->map_img || !mlx->minimap->map_img)
		exit_err(cubed, 5);
	mlx->surfaces->buffer_array = ft_calloc(WIN_H, sizeof(unsigned int *));
	if  (!mlx->surfaces->buffer_array)
		exit_err(cubed, 5);
}

static void	malloc_img_structs(t_cubed *cubed, t_mlx *mlx)
{
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->text_n = malloc(sizeof(t_our_img));
	mlx->text_s = malloc(sizeof(t_our_img));
	mlx->text_e = malloc(sizeof(t_our_img));
	mlx->text_w = malloc(sizeof(t_our_img));
	mlx->automap_player = malloc(sizeof(t_our_img));
	mlx->minimap_player = malloc(sizeof(t_our_img));
	if (!mlx->text_n || !mlx->text_s || !mlx->text_e || !mlx->text_w \
		|| !mlx->automap_player || !mlx->minimap_player)
		exit_err(cubed, 5);
}
/*
static void	init_renderer(t_cubed *cubed, t_list *renderer)
{
	t_render	*ray;
	int			i;

	i = 0;
	while (i < WIN_W)
	{
		renderer->content = malloc(sizeof(t_render));
		if (!renderer->content)
			exit_err(cubed, 5);
		ray = renderer->content;
		ray->col = i;
		i++;
		if (i < WIN_W)
		{
			renderer->next = malloc(sizeof(t_list));
			if (!renderer->next)
				exit_err(cubed, 5);
			renderer = renderer->next;
		}
	}
	renderer->next = NULL;
}
*/
static void	init_buffer_array(t_cubed *cubed, t_canvas *surfaces)
{
	unsigned int	**buffer_arr;
	int				i;

	buffer_arr = surfaces->buffer_array;
	i = 1;
	while (i <= WIN_H)
	{
		buffer_arr[i - 1] = ft_calloc(i, sizeof(unsigned int));
		if (!buffer_arr[i - 1])
			exit_err(cubed, 5);
		i++;
	}
}

void	init_mlx_struct(t_cubed *cubed)
{
	t_mlx	*mlx;

	mlx = cubed->mlx;
	malloc_img_structs(cubed, mlx);
	malloc_canvas_structs(mlx, cubed);
//	mlx->renderer = malloc(sizeof(t_list));
	mlx->proj_plane_height = WIN_H - (WIN_H / 6);
	init_img_struct(mlx->text_n);
	init_img_struct(mlx->text_s);
	init_img_struct(mlx->text_e);
	init_img_struct(mlx->text_w);
	init_img_struct(mlx->automap_player);
	init_img_struct(mlx->minimap_player);
	init_img_struct(mlx->automap->map_img);
	init_img_struct(mlx->minimap->map_img);
	init_img_struct(mlx->surfaces->map_img);
	init_buffer_array(cubed, mlx->surfaces);
//	init_renderer(cubed, mlx->renderer);
}
