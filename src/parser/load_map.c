#include "../../include/cub3d.h"

static int	get_max_map_lines(t_mlx *mlx, char *path)
{
	int		map_fd;
	char	*line;
	int		max_line;

	map_fd = open(path, O_RDONLY);
	if (map_fd == -1)
		exit_err(mlx, 2);
	line = NULL;
	max_line = 0;
	line = get_next_line(map_fd);
	while (line)
	{
		free(line);
		line = get_next_line(map_fd);
		max_line++;
	}
	if (close(map_fd) == -1)
		exit_err(mlx, 3);
	return (max_line);
}

int load_map(t_mlx *mlx, char *path)
{
	int		map_fd;
	char	*line;
	int		max_line;

	max_line = get_max_map_lines(mlx, path);
	map_fd = open(path, O_RDONLY);
	if (map_fd == -1)
		exit_err(mlx, 2);
	line = NULL;
	mlx->map = (unsigned char **)ft_calloc(sizeof(unsigned char *), (max_line - 8 + 1));
	(void)line;
	// printf("%d\n", max_line - 8);



	if (close(map_fd) == -1)
		exit_err(mlx, 3);
	return (0);
}

	// 	map_fd = open(path, O_RDONLY);
	// 	if (line == NULL)
	// 		exit_err(mlx, 1);
	// 	free(line);
	// 	i++;
	// }
	// line = get_next_line(map_fd);
