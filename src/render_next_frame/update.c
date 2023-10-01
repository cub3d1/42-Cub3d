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

void	update_player_pos(t_cubed *cubed, t_keys *keys)
{
	if (keys->w && !keys->s)
	{
		cubed->player->pos_x += cos(cubed->player->angle * M_PI / 180) * VELOCITY;
		cubed->player->pos_y -= sin(cubed->player->angle * M_PI / 180) * VELOCITY;
	}
	if (keys->s && !keys->w)

	{
		cubed->player->pos_x -= cos(cubed->player->angle * M_PI / 180) * VELOCITY;
		cubed->player->pos_y += sin(cubed->player->angle * M_PI / 180) * VELOCITY;
	}
	if (keys->a && !keys->d)
	{
		cubed->player->pos_x += cos((cubed->player->angle + 90) * M_PI / 180) * VELOCITY;
		cubed->player->pos_y -= sin((cubed->player->angle + 90) * M_PI / 180) * VELOCITY;
	}
	if (keys->d && !keys->a)
	{
		cubed->player->pos_x -= cos((cubed->player->angle + 90) * M_PI / 180) * VELOCITY;
		cubed->player->pos_y += sin((cubed->player->angle + 90) * M_PI / 180) * VELOCITY;
	}
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