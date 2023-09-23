#include "../../include/cub3d.h"

static int cub_check(char *arg)
{
	int i = 0;

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

void parser(t_mlx *mlx, char *arg)
{
	if (cub_check(arg) == 1)
		exit(0);
	(void)mlx;
}