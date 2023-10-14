#include "../../include/cub3d.h"

// static void 	init_rwf(t_cubed *cubed, t_player *player, t_mlx *mlx)
// {
// 	player = cubed->player;
// 	mlx = cubed->mlx;
// }

// static int done() { return 0; }

// static void print_vectors (t_player *player, double rayDirX, double rayDirY)
// {
// 	printf("pos_x = %.1f | pos_y = %.1f | ", player->pos_x, player->pos_y);
// 	printf("dir_x = %.1f | dir_y = %.1f | ", player->dir_x, player->dir_y);
// 	printf("plane_vectorX = %.1f | plane_vectorY = %.1f\n", player->plane_vector_x, player->plane_vector_y);
// 	printf("rayDirX = %.1f | rayDirY = %.1f\n", rayDirX, rayDirY);
// }

void render_whole_frame(t_cubed *cubed)
{
	t_player	*player = cubed->player;
	t_mlx		*mlx = cubed->mlx;

	double cameraX = 0;
  	double rayDirX = player->dir_x + player->plane_vector_x * cameraX;
  	double rayDirY = player->dir_y + player->plane_vector_y * cameraX;

	// print_vectors(player, rayDirX, rayDirY);

	// while(!done())
 //  	{
 //  		ft_printf_fd(1, "yoooo\n");
 //  	}

  	(void)cubed; (void)mlx; (void)player; (void)cameraX; (void)rayDirY; (void)rayDirX;
}