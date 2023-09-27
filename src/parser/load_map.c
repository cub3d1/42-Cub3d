#include "../../include/cub3d.h"

int load_map(t_mlx *mlx, char *path)
{
    int map_fd;

    map_fd = open(path, O_RDONLY);
    if (map_fd == -1)
        exit_err(mlx, 2);
    
    // mlx->map = (unsigned char **)malloc(sizeof(unsigned char *) * 2);

    if (close(map_fd) == -1)
        exit_err(mlx, 3);
    return (0);
}
