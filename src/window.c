
#include "cub3d.h"

void	raycasting(t_data *data)
{
	int		i;
	t_wall	*wall;
	double	camera_x;
	double	step;

	i = 0;
	wall = data->wall;
	while (i < WIDTH)
	{
		wall->hit = 0;
		camera_x = 2 * i / (double)WIDTH - 1;
		calculate_length_ray(data, camera_x);
		calculate_sidedist(data);
		while (wall->hit == 0)
		{
			search_wall(data);
			if (data->map->map[data->y->map][data->x->map] == '1')
				wall->hit = 1;
		}
		calculate_wall_height(data);
		step = 1.0 * DIM_TXTR / wall->line_height;
		vertical_line(i, data, calcul_xtxtr(data), step);
		i++;
	}
}

int	move(t_data *data)
{
	mlx_destroy_image(data->mlx, data->map->background.img);
	move_left_right(data);
	move_up_down(data);
	rotate(data);
	draw(data);
	return (0);
}

int	close_cross(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

int	initialize(int fd, t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (0);
	if (read_textures(fd, data) == 0)
		return (destroy(data),
			mlx_destroy_display(data->mlx), free(data->mlx), 0);
	get_texture_adress(data);
	data->win = mlx_new_window(data->mlx,
			WIDTH, HEIGHT, "cub3d");
	if (data->win == NULL)
	{
		free(data->win);
		return (0);
	}
	return (1);
}
