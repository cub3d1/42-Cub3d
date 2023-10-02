#include "../../include/cub3d.h"

void	update_angle(t_cubed *cubed)
{
	int mouse_x;
	int mouse_y;

	if (cubed->keys->right && !cubed->keys->left)
	{
		cubed->player->angle -= SENSITIVITY * 0.1;
		if (cubed->player->angle < 0)
			cubed->player->angle = 360;
	}
	else if (cubed->keys->left && !cubed->keys->right)
	{
		cubed->player->angle += SENSITIVITY * 0.1;
		if (cubed->player->angle > 360)
			cubed->player->angle = 0;
	}
	mlx_mouse_get_pos(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr, &mouse_x, &mouse_y);
	if (mouse_x > WIN_W / 2)
	{
		cubed->player->angle -= SENSITIVITY;
		if (cubed->player->angle < 0)
			cubed->player->angle = 360;
	}
	else if (mouse_x < WIN_W / 2)
	{
		cubed->player->angle += SENSITIVITY;
		if (cubed->player->angle > 360)
			cubed->player->angle = 0;
	}
	mlx_mouse_move(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr, WIN_W / 2, WIN_H / 2);
}

//	this implementation is very raw and totally sucks
//	it's just a basic idea for the collisions
static void	collision_check(t_cubed *cubed, t_keys *keys)
{
	float	next_x;
	float	next_y;

	if (keys->w && !keys->s)
	{
		next_x += cos(cubed->player->angle * M_PI / 180) * VELOCITY;
		next_y -= sin(cubed->player->angle * M_PI / 180) * VELOCITY;
		if (cubed->map[(int)next_y][(int)next_x] == '1')
		{
			if ((int)next_x != (int)cubed->player->pos_x)
				//	collide on x axis
			if ((int)next_y != (int)cubed->player->pos_y)
				//	collide on y axis
		}
	}
	if (keys->s && !keys->w)
	{
		next_x -= cos(cubed->player->angle * M_PI / 180) * VELOCITY;
		next_y += sin(cubed->player->angle * M_PI / 180) * VELOCITY;
		if (cubed->map[(int)next_y][(int)next_x] == '1')
		{
			if ((int)next_x != (int)cubed->player->pos_x)
				//	collide on x axis
			if ((int)next_y != (int)cubed->player->pos_y)
				//	collide on y axis
		}
	}
	if (keys->a && !keys->d)
	{
		next_x += cos((cubed->player->angle + 90) * M_PI / 180) * VELOCITY;
		next_y -= sin((cubed->player->angle + 90) * M_PI / 180) * VELOCITY;
		if (cubed->map[(int)next_y][(int)next_x] == '1')
		{
			if ((int)next_x != (int)cubed->player->pos_x)
				//	collide on x axis
			if ((int)next_y != (int)cubed->player->pos_y)
				//	collide on y axis
		}
	}
	if (keys->d && !keys->a)
	{
		next_x -= cos((cubed->player->angle + 90) * M_PI / 180) * VELOCITY;
		next_y += sin((cubed->player->angle + 90) * M_PI / 180) * VELOCITY;
		if (cubed->map[(int)next_y][(int)next_x] == '1')
		{
			if ((int)next_x != (int)cubed->player->pos_x)
				//	collide on x axis
			if ((int)next_y != (int)cubed->player->pos_y)
				//	collide on y axis
		}
	}
	cubed->player->pos_x = next_x;
	cubed->player->pos_y = next_y;
}

void	update_player_pos(t_cubed *cubed, t_keys *keys)
{
	collision_check(cubed, keys);
	if (cubed->player->pos_y < 0)
		cubed->player->pos_y = 0;
	if (cubed->player->pos_y > WIN_H)
		cubed->player->pos_y = WIN_H;
	if (cubed->player->pos_x < 0)
		cubed->player->pos_x = 0;
	if (cubed->player->pos_x > WIN_W)
		cubed->player->pos_x = WIN_W;
	cubed->player->pos_x_array = cubed->player->pos_x * cubed->map_width / WIN_W;
	cubed->player->pos_y_array = cubed->player->pos_y * cubed->map_height / WIN_H;
}
