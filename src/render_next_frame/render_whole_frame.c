#include "../../include/cub3d.h"

// static void 	init_rwf(t_cubed *cubed, t_player *player, t_mlx *mlx)
// {
// 	player = cubed->player;
// 	mlx = cubed->mlx;
// }

static int done() { return 0; }

static void print_vectors (t_rwf *rwf)
{
	printf("rayDirX = %.1f | rayDirY = %.1f\n", rayDirX, rayDirY);
}

void render_whole_frame(t_cubed *cubed)
{
	t_player	*player = cubed->player;
	t_mlx		*mlx = cubed->mlx;
	t_rwf		rwf;

	rwf.cameraX = 0;
  	rwf.rayDirX = player->dir_x + player->plane_vector_x * rwf.cameraX;
  	rwf.rayDirY = player->dir_y + player->plane_vector_y * rwf.cameraX;

	int deltaDistX;
	int deltaDistY;

	// print_vectors(player, rayDirX, rayDirY);

	int x = 0;
		while(!done())
	 	{
			while (x < WIN_W)
			{
				rwf.cameraX = 2 * x / (double)WIN_W - 1;			
				rwf.rayDirX = player->dir_x + player->plane_vector_x * rwf.cameraX;
				rwf.rayDirY = player->dir_y + player->plane_vector_y * rwf.cameraX;

				deltaDistX = sqrt(1 + (rwf.rayDirY * rwf.rayDirY) / (rwf.rayDirX * rwf.rayDirX));
				deltaDistY = sqrt(1 + (rwf.rayDirX * rwf.rayDirX) / (rwf.rayDirY * rwf.rayDirY));
				
				
				
				x++;
			}
	 	}

  	(void)cubed; (void)mlx; (void)player; (void)cameraX; (void)rayDirY; (void)rayDirX;
}