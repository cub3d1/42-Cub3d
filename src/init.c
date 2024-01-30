/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:21:14 by fmouronh          #+#    #+#             */
/*   Updated: 2024/01/25 17:48:50 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_key_struct(t_keys *keys)
{
	keys->w = false;
	keys->a = false;
	keys->s = false;
	keys->d = false;
	keys->left = false;
	keys->right = false;
	keys->show_automap = false;
	keys->show_minimap = false;
}

static void	set_player_direction(t_player *player, char tkn)
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

void	init_player_struct(t_player *player, char **map, int y)
{
	int	x;

	x = 0;
	while (map[y][x] && map[y][x] != 'N' && map[y][x] != 'S' \
		&& map[y][x] != 'E' && map[y][x] != 'W')
		x++;
	player->pos_x_array = (double)x + (double)0.5;
	player->pos_y_array = (double)y + (double)0.5;
	player->pos_x = (((double)(x + 0.5)) * WIN_W) / get_biggest_line(map);
	player->pos_y = (((double)(y + 0.5)) * WIN_H) / get_array_size(map);
	set_player_direction(player, map[y][x]);
}

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
