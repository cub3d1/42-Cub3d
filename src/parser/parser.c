#include "../../include/cub3d.h"
/*
static void	skip_empty_lines(int map_fd, char **line)
{
	while (*line && **line == '\n')
	{
		free(*line);
		*line = get_next_line(map_fd);
	}
}
*/
static int cub_check(char *arg)
{
	int i;

	i = 0;
	if (ft_strlen(arg) < 5)
	{
		ft_printf_fd(1, "Error\nArgument too short\n");
		return (1);
	}
	i = ft_strlen(arg) - 4;
	if (ft_strncmp(arg + i, ".cub", 4) != 0)
	{
		ft_printf_fd(1, "Error\nArgument must be a .cub file\n");
		return (1);
	}
	return (0);
}
//	must be able to parse in any order...
static bool	file_content_ok(char *arg)
{
	int	map_fd;

	map_fd = open(arg, O_RDONLY);
	if (map_fd == -1)
		exit(2);
	if (!textures_ok(map_fd))
		return (false);
	map_fd = open(arg, O_RDONLY);
	if (map_fd == -1)
		exit(2);
	if (!color_ok(map_fd))
		return (false);
	map_fd = open(arg, O_RDONLY);
	if (map_fd == -1)
		exit(2);
	if (!map_pos_ok(map_fd))
		return (false);
	return (true);
}
/*
static bool	map_layout_ok(char *arg)
{
	int	map_offset;

	map_offset = find_map_offset(arg); //	return -1 if map not found
	if (map_offset == -1)
		return (false);
*/
/*
	must check if:
		all characters are valid
		map is surrounded by walls - use flood fill?
		map is at end of file (maybe that can be done in content_check?)
		map has no empty lines
		only 1 player tile
*/
/*	(void)arg;
	return (true);
}
*/
void	parser(t_mlx *mlx, char *arg)
{
	/*	check file format			*/
	if (cub_check(arg) == 1)
		exit(0);
	/*	check file content layout	*/
	if (!file_content_ok(arg))
	{
		ft_printf_fd(2, "Error\nInvalid map file content\n");
		exit(0);
	}
	/*	check map layout			*/
//	if (!map_layout_ok(arg))
//		exit(0);
	/*	load map into ram			*/
	// load_map(mlx, arg);
	(void)mlx;	//	remove when done
}
