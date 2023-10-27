/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:38:47 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/27 19:42:43 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void 	init_rwf(t_rwf *rwf)
{
	rwf->cameraX = 0;
	rwf->rayDirX = 0;
	rwf->rayDirY = 0;
	rwf->deltaDistX = 0;
	rwf->deltaDistY = 0;
	rwf->sideDistX = 0;
	rwf->sideDistY = 0;
	rwf->perpWallDist = 0;
	rwf->mapX = 0;
	rwf->mapY = 0;
	rwf->stepX = 0;	
	rwf->stepY = 0;
	rwf->hit = 0;
	rwf->side = 0;
	rwf->lineHeight = 0;
}

// static int done() { return 0; }

static void update_vectors(t_rwf *rwf, t_player *player, int x)
{
	rwf->cameraX = 2 * x / (double)WIN_W - 1;
	rwf->rayDirX = player->dir_x + player->plane_vector_x * rwf->cameraX;
	rwf->rayDirY = player->dir_y + player->plane_vector_y * rwf->cameraX;
	if (rwf->rayDirX == 0)
		rwf->rayDirX = 0.00000000001;
	if (rwf->rayDirY == 0)
		rwf->rayDirY = 0.00000000001;

	rwf->deltaDistX = sqrt(1 + (rwf->rayDirY * rwf->rayDirY) / (rwf->rayDirX * rwf->rayDirX));
	rwf->deltaDistY = sqrt(1 + (rwf->rayDirX * rwf->rayDirX) / (rwf->rayDirY * rwf->rayDirY));
}

static void update_map_steps (t_rwf *rwf, t_player *player)
{
	rwf->mapX = (int)player->pos_x_array;
	rwf->mapY = (int)player->pos_y_array;

	if (rwf->rayDirX < 0)
	{
		rwf->stepX = -1;
		rwf->deltaDistX = (player->pos_x_array - rwf->mapX) * rwf->deltaDistX;
	}
	else
	{
		rwf->stepX = 1;
		rwf->deltaDistX = (rwf->mapX + 1.0 - player->pos_x_array) * rwf->deltaDistX;
	}
	if (rwf->rayDirY < 0)
	{
		rwf->stepY = -1;
		rwf->deltaDistY = (player->pos_y_array - rwf->mapY) * rwf->deltaDistY;
	}
	else
	{
		rwf->stepY = 1;
		rwf->deltaDistY = (rwf->mapY + 1.0 - player->pos_y_array) * rwf->deltaDistY;
	}
}

void fill_renderer(t_rwf rwf, t_render *ray)
{
	ray->wall_x = rwf.mapX;
	ray->wall_y = rwf.mapY;
	ray->plane_x = rwf.rayDirX;
	ray->plane_y = rwf.rayDirY;
	if (rwf.side == 0)
		ray->hit = 'x';
	else if (rwf.side == 1)
		ray->hit = 'y';
}

// static void print_vectors (t_rwf *rwf)
// {
// 	printf("[RWF] rayDirX = %.1f|rayDirY = %.1f|", rwf->rayDirX, rwf->rayDirY);
// 	printf("[RWF] cameraX = %.1f|", rwf->cameraX);
// 	printf("[RWF] deltaDistX = %.1f|deltaDistY = %.1f|", rwf->deltaDistX, rwf->deltaDistY);
// 	printf("[RWF] sideDistX = %.1f|sideDistY = %.1f|", rwf->sideDistX, rwf->sideDistY);

// 	// printf("\n");

// 	(void)rwf;
// }

void raycaster(t_cubed *cubed, t_list *renderer)
{
	t_player	*player = cubed->player;
	t_mlx		*mlx = cubed->mlx;
	t_rwf		rwf;
	t_render	*ray;
	
	init_rwf(&rwf);

	int x = 0;

	while (x < WIN_W)
	{
		update_vectors(&rwf, player, x);
		update_map_steps(&rwf, player);

		// print_vectors(&rwf);
		
		while (rwf.hit == 0)
		{
			if (rwf.sideDistX < rwf.sideDistY)
			{
				rwf.sideDistX += rwf.deltaDistX;
				rwf.mapX += rwf.stepX;
				rwf.side = 0;
			}
			else
			{
				rwf.sideDistY += rwf.deltaDistY;
				rwf.mapY += rwf.stepY;
				rwf.side = 1;
			}
			if (cubed->map[rwf.mapY][rwf.mapX] == '1')
				rwf.hit = 1;
		}

		// ft_printf_fd(1, "[RWF] rwf.mapX = %d|rwf.mapY = %d\n", rwf.mapX, rwf.mapY);

		// printf("[RWF] rwf.sideDistX = %.1f|rwf.sideDistY = %.1f\n", rwf.sideDistX, rwf.sideDistY);

		// printf("[RWF] rwf.deltaDistX = %.1f|rwf.deltaDistY = %.1f\n", rwf.deltaDistX, rwf.deltaDistY); 
		
		// exit(1);
		
		if (rwf.side == 0)
			rwf.perpWallDist = (rwf.sideDistX);					
		else
			rwf.perpWallDist = (rwf.sideDistY);

		// // rwf.perpWallDist = 2;
		// printf("[RWF] rwf.perpWallDist = %.1f\n", rwf.perpWallDist);

		rwf.lineHeight = (int)(WIN_H / rwf.perpWallDist);


		// rwf.lineHeight = 400;
		// printf("[RWF] rwf.lineHeight = %d\n", rwf.lineHeight);
		// // exit(1);

			int drawStart = -rwf.lineHeight / 2 + WIN_H / 2;
			if(drawStart < 0) drawStart = 0;

			int drawEnd = rwf.lineHeight / 2 + WIN_H / 2;
			if(drawEnd >= WIN_H) drawEnd = WIN_H - 1;
		
		// ft_printf_fd(1, "[RWF] drawStart = %d|drawEnd = %d\n", drawStart, drawEnd);
		// exit(1);
		// int color = 0;
		// switch(rwf.side)
      	// {
	    //     case 0:  color = 0x000000FF;  break; //blue
	    //     case 1:  color = 0x0000FF00;  break; //green
      	// }
		// while (drawStart < drawEnd)
		// {
		// 	mlx_pixel_put(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr, x, 	drawStart, color);
		// 	drawStart++;
		// }
		// usleep(100);
		ray = renderer->content;
		fill_renderer(rwf, ray);
		renderer = renderer->next;
		init_rwf(&rwf);
		x++;
	}
	// ft_printf_fd(1, "walls drawn!\n");
	// sleep(2);
	(void)player; (void)mlx; (void)cubed;
}
