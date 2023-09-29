#include "../include/cub3d.h"

/*	init all struct members to NULL or their default value	*/
void	init_mlx_struct(t_mlx *mlx)
{
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->text_N = NULL;
	mlx->text_S = NULL;
	mlx->text_E = NULL;
	mlx->text_W = NULL;
}

void	set_player_direction(t_player *player, char tkn)
{
	if (tkn == 'N')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (tkn == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (tkn == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (tkn == 'W')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
}

void	init_player_struct(t_player *player, char *map_row, int y)
{
	int	x;

	x = 0;
	while (map_row[x] && map_row[x] !='N' && map_row[x] != 'S'
			&& map_row[x] != 'E' && map_row[x] != 'W')
		x++;
	player->pos_x = (float)x + 0.5;
	player->pos_y = (float)y + 0.5;
	set_player_direction(player, map_row[x]);
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
}

void	init_cubed(t_cubed *cubed)
{
	cubed->mlx = malloc(sizeof(t_mlx));
	cubed->player = malloc(sizeof(t_player));
	if (!cubed->mlx || !cubed->player)
		exit_err(cubed, 5);
	init_mlx_struct(cubed->mlx);
	cubed->map = NULL;
	cubed->texture_paths = NULL;
}
