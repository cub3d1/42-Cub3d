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
		exit_err(cubed, 2);
	if (!textures_ok(map_fd, cubed))
		return (false);
	map_fd = open(arg, O_RDONLY);
	if (map_fd == -1)
		exit_err(cubed, 2);
	if (!color_ok(map_fd, cubed))
		return (false);
	map_fd = open(arg, O_RDONLY);
	if (map_fd == -1)
		exit_err(cubed, 2);
	if (!map_pos_ok(map_fd, cubed))
		return (false);
	return (true);
}

// static bool	map_layout_ok(t_cubed *cubed)
// {

// 	if (!map_tokens_ok(cubed))
// 	{
// 		ft_printf_fd(2, "Error\nInvalid map tokens\n");
// 		return (false);
// 	}
// 	if (!player_token_ok(cubed))
// 	{
// 		ft_printf_fd(2, "Error\nInvalid player token\n");
// 		return (false);
// 	}
// 	if (!layout_enclosed(cubed))
// 	{
// 		ft_printf_fd(2, "Error\nMap not enclosed\n");
// 		return (false);
// 	}
// 	return (true);
// }

void	parser(t_cubed *cubed, char *arg)
{
	/*	check file format			*/

	if (cub_check(arg) == 1)
		exit_err(cubed, 0);
	/*	check file content layout	*/
	if (!file_content_ok(arg, cubed))
	{
		ft_printf_fd(2, "Error\nInvalid map file content\n");
		exit_err(cubed, 0);
	}
	/*	load map into ram			*/
	load_map(cubed, arg);
	/*	check map layout			*/
	// if (!map_layout_ok(cubed))
	// 	exit_err(cubed, 0);
}
