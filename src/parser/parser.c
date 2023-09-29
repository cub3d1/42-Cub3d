#include "../../include/cub3d.h"

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
	if (!map_tokens_ok(cubed))
		return (false);
	if (!player_token_ok(cubed))
		return (false);
	if (!layout_enclosed(cubed))
		return (false);
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
	/*	load map into ram			*/
	load_map(cubed, arg);
	/*	check map layout			*/
	if (!map_layout_ok(arg, cubed))
		abort_init(0, cubed);
}
