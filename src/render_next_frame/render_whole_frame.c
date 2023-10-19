#include "../../include/cub3d.h"

// static void 	init_rwf(t_cubed *cubed, t_player *player, t_mlx *mlx)
// {
// 	player = cubed->player;
// 	mlx = cubed->mlx;
// }

static int done() { return 0; }

// static void print_vectors (t_player *player, double rayDirX, double rayDirY)
// {
// 	printf("rayDirX = %.1f | rayDirY = %.1f\n", rayDirX, rayDirY);
// }

void render_whole_frame(t_cubed *cubed)
{
	t_player	*player = cubed->player;
	t_mlx		*mlx = cubed->mlx;

	double cameraX = 0;
  	double rayDirX = player->dir_x + player->plane_vector_x * cameraX;
  	double rayDirY = player->dir_y + player->plane_vector_y * cameraX;

	int deltaDistX;
	int deltaDistY;

	// print_vectors(player, rayDirX, rayDirY);

	int x = 0;
		while(!done())
	 	{
			while (x < WIN_W)
			{
				cameraX = 2 * x / (double)WIN_W - 1;			
				rayDirX = player->dir_x + player->plane_vector_x * cameraX;
				rayDirY = player->dir_y + player->plane_vector_y * cameraX;

				deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
				deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
				
				
				
				x++;
			}
	 	}

  	(void)cubed; (void)mlx; (void)player; (void)cameraX; (void)rayDirY; (void)rayDirX;
}