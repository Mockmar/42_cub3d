
#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_ceiling(int y, t_data *data)
{
	int				x;
	int				pixel;
	unsigned char	*buffer;

	buffer = (unsigned char *)mlx_get_data_addr(data->map->background.img,
			&data->map->background.bpp, &data->map->background.line_length,
			&data->map->background.endian);
	x = 0;
	while (x < WIDTH)
	{
		pixel = (y * data->map->background.line_length) + (x * 4);
		buffer[pixel + 0] = data->ceiling->b;
		buffer[pixel + 1] = data->ceiling->g;
		buffer[pixel + 2] = data->ceiling->r;
		buffer[pixel + 3] = 0;
		x++;
	}
}

void	draw_floor(int y, t_data *data)
{
	int				x;
	int				pixel;
	unsigned char	*buffer;

	buffer = (unsigned char *)mlx_get_data_addr(data->map->background.img,
			&data->map->background.bpp, &data->map->background.line_length,
			&data->map->background.endian);
	x = 0;
	while (x < WIDTH)
	{
		pixel = (y * data->map->background.line_length) + (x * 4);
		buffer[pixel + 0] = data->floor->b;
		buffer[pixel + 1] = data->floor->g;
		buffer[pixel + 2] = data->floor->r;
		buffer[pixel + 3] = 0;
		x++;
	}
}

void	draw(t_data *data)
{
	int	y;

	y = 0;
	data->map->background.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	while (y <= HEIGHT / 2)
	{
		draw_ceiling(y, data);
		y++;
	}
	while (y < HEIGHT)
	{
		draw_floor(y, data);
		y++;
	}
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->map->background.img, 0, 0);
}
