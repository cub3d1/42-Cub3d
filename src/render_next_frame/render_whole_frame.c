#include "../../include/cub3d.h"

// static void 	init_rwf(t_cubed *cubed, t_player *player, t_mlx *mlx)
// {
// 	player = cubed->player;
// 	mlx = cubed->mlx;
// }

// static int done() { return 0; }

// static void print_vectors (t_player *player, double rayDirX, double rayDirY)
// {
// 	ft_printf_fd(1, "------------------------\n");

// 	ft_printf_fd(1, "pos_x = %d | pos_y = %d | ", player->pos_x, player->pos_y);
// 	ft_printf_fd(1, "dir_x = %d | dir_y = %d | ", player->dir_x, player->dir_y);
// 	ft_printf_fd(1, "plane_vectorX = %d | plane_vectorY = %d\n", player->plane_vector_x, player->plane_vector_y);
// 	ft_printf_fd(1, "rayDirX = %d | rayDirY = %d\n", rayDirX, rayDirY);

// 	ft_printf_fd(1, "------------------------\n");
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