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
static bool	file_content_ok(char *arg, t_cubed *cubed)
{
	int	map_fd;

	map_fd = open(arg, O_RDONLY);
	if (map_fd == -1)
		abort_init(2, cubed);
	if (!textures_ok(map_fd, cubed))
		return (false);
	map_fd = open(arg, O_RDONLY);
	if (map_fd == -1)
		abort_init(2, cubed);
	if (!color_ok(map_fd))
		return (false);
	map_fd = open(arg, O_RDONLY);
	if (map_fd == -1)
		abort_init(2, cubed);
	if (!map_pos_ok(map_fd))
		return (false);
	return (true);
}

static bool	map_layout_ok(char *arg, t_cubed *cubed)
{
	int	map_offset;

	map_offset = find_map_offset(arg);
	if (!map_tokens_ok(arg, map_offset))
		return (false);
	if (!player_token_ok(arg, map_offset))
		return (false);
	if (!layout_enclosed(arg, map_offset))
		return (false);
/*
	must check if:
		all characters are valid
		map is surrounded by walls - use flood fill?
		only 1 player tile
*/
	return (true);
}

void	parser(t_cubed *cubed, char *arg)
{
	/*	check file format			*/
	if (cub_check(arg) == 1)
		abort_init(0, cubed);
	/*	check file content layout	*/
	if (!file_content_ok(arg, cubed))
	{
		ft_printf_fd(2, "Error\nInvalid map file content\n");
		abort_init(0, cubed);
	}
	/*	check map layout			*/
	if (!map_layout_ok(arg, cubed))
		abort_init(0, cubed);
	/*	load map into ram			*/
	load_map(cubed, arg);
}
