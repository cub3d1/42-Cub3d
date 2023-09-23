#include "../include/cub3d.h"

int main()
{
	int fd = open("test.txt", O_RDONLY);
	
	char *str = get_next_line(fd);
	ft_printf_fd(1, "%s\n", str);
	free(str);

	str = get_next_line(fd);
	ft_printf_fd(1, "%s\n", str);
	free(str);

	close(fd);
	return (0);
}