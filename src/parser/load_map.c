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

void advance_gnl_to_map(int map_fd)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		free(get_next_line(map_fd));
		i++;
	}
}

static void	get_map_to_array(int map_fd, int max_line, t_mlx *mlx)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(map_fd);
	while (i < max_line)
	{
		mlx->map[i] = (unsigned char *)ft_strdup(line);
		free(line);
		line = NULL;
		if (++i < max_line)
			line = get_next_line(map_fd);
	}
	if (line != NULL)
		free(line);
}

// void print_map(t_mlx *mlx)
// {
// 	int i;

// 	i = 0;
// 	while (mlx->map[i])
// 	{
// 		ft_printf_fd(1, "%s", mlx->map[i]);
// 		i++;
// 	}
// }

int load_map(t_mlx *mlx, char *path)
{
	int		map_fd;
	int		max_line;

	max_line = get_max_map_lines(mlx, path);
	map_fd = open(path, O_RDONLY);
	if (map_fd == -1)
		exit_err(mlx, 2);
	mlx->map = (unsigned char **)ft_calloc(sizeof(unsigned char *), (max_line - 8 + 1));

	advance_gnl_to_map(map_fd); /* advance the gnl fd to beginning of the map */
	get_map_to_array(map_fd, max_line - 8, mlx); /* load map into variable mlx.map */
	// print_map(mlx); /* print map to stdout */

	if (close(map_fd) == -1)
		exit_err(mlx, 3);
	return (0);
}
