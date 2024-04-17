
#include "cub3d.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	destroy(t_data *data)
{
	if (data->map->background.img != NULL)
		mlx_destroy_image(data->mlx, data->map->background.img);
	free_xpm_ptr(data);
}

int	valid_file(char **s, int ac, int fd)
{
	char		*tmp;
	struct stat	buf;

	if (ac != 2)
		return (ft_printf("Error: wrong number of arguments\n"), 0);
	tmp = ft_strchr(s[1], '.');
	if (tmp == NULL)
		return (ft_printf("Error: this file is not a .cub\n"), 0);
	if (ft_strncmp(".cub", tmp, 4) != 0)
		return (ft_printf("Error: this file is not a .cub\n"), 0);
	if (fd == -1)
		return (printf("Error: this file doesn't exist\n"), 0);
	fstat(fd, &buf);
	if (S_ISDIR(buf.st_mode))
		return (printf("Error: bad file\n"), 0);
	return (1);
}

static void	init_xpm_ptr(t_data *data)
{
	data->y->map = 0;
	data->x->map = 0;
	data->map->map = NULL;
	data->map->background.img = NULL;
	data->txtr[0].img = NULL;
	data->txtr[1].img = NULL;
	data->txtr[2].img = NULL;
	data->txtr[3].img = NULL;
}

void	init_count(t_count *count, t_data *data)
{
	t_floor		floor;
	t_ceiling	ceiling;
	t_x			x;
	t_y			y;
	t_wall		wall;

	data->x = &x;
	data->y = &y;
	data->wall = &wall;
	data->x->pos = 0;
	data->y->pos = 0;
	data->x->dir = 0;
	data->y->dir = 0;
	data->x->plane = 0;
	data->y->plane = 0;
	data->ceiling = &ceiling;
	data->floor = &floor;
	count->perso = 0;
	count->floor = 0;
	count->ceiling = 0;
	count->east = 0;
	count->west = 0;
	count->north = 0;
	count->south = 0;
	init_xpm_ptr(data);
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;
	t_map	map;
	t_count	count;

	fd = open(av[ac - 1], O_RDONLY);
	if (valid_file(av, ac, fd) == 0)
		return (0);
	data.map = &map;
	data.count = &count;
	init_count(&count, &data);
	init_key(&data);
	if (initialize(fd, &data) == 0)
		return (close(fd), 0);
	close(fd);
	draw(&data);
	mlx_hook(data.win, 2, 1L << 0, &key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, &key_release, &data);
	mlx_hook(data.win, 17, 1L << 17, &close_cross, &data);
	mlx_loop_hook(data.mlx, &move, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	return (destroy(&data), mlx_destroy_display(data.mlx), my_free(&data), 0);
}
