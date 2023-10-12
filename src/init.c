/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:21:14 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/01 10:19:22 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*	init all struct members to NULL or their default value	*/
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

static void	init_mlx_struct(t_cubed *cubed)
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

void	init_key_struct(t_keys *keys)
{
	keys->w = false;
	keys->a = false;
	keys->s = false;
	keys->d = false;
	keys->left = false;
	keys->right = false;
	keys->show_minimap = false;
}

void	set_player_direction(t_player *player, char tkn)
{
	if (tkn == 'N')
		player->angle = 90;
	else if (tkn == 'S')
		player->angle = 270;
	else if (tkn == 'E')
		player->angle = 0;
	else if (tkn == 'W')
		player->angle = 180;
}

float	get_biggest_line(char **map)
{
	int		i;
	int		j;
	int		biggest;

	i = 0;
	biggest = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > biggest)
			biggest = j;
		i++;
	}
	return ((float)biggest);
}

float	get_array_size(char **map)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (map[i])
	{
		size++;
		i++;
	}
	return ((float)size);
}

void	init_player_struct(t_player *player, char **map, int y)
{
	int	x;

	x = 0;
	while (map[y][x] && map[y][x] != 'N' && map[y][x] != 'S' \
		&& map[y][x] != 'E' && map[y][x] != 'W')
		x++;
	player->pos_x_array = (float)x + 0.5;
	player->pos_y_array = (float)y + 0.5;
	player->pos_x = ((float)x * WIN_W) / get_biggest_line(map);
	player->pos_y = ((float)y * WIN_H) / get_array_size(map);
	set_player_direction(player, map[y][x]);
}

	//	set player->direction according to token in map_row[x]
/*
	idea:
		direction can be an xy float vector with values between -1 and 1
		where 1 points to the next tile in a given direction
		and -1 to the prev one
		like:
					 x
		*************
		*           *
		*           *
		*    ^      * player is facing north
		*           *	player->dir_x = 0
		*           *	player->dir_y = -1
		*************
	   y
*/
void	init_cubed(t_cubed *cubed)
{
	cubed->mlx = malloc(sizeof(t_mlx));
	cubed->player = malloc(sizeof(t_player));
	cubed->keys = malloc(sizeof(t_keys));
	if (!cubed->mlx || !cubed->player || !cubed->keys)
		exit_err(cubed, 5);
	init_mlx_struct(cubed);
	init_key_struct(cubed->keys);
	cubed->map = NULL;
	cubed->texture_paths = NULL;
}
