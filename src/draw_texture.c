
#include "cub3d.h"

int	walltxtr_indentifier(t_data *data, t_wall *wall)
{
	if (wall->side == 0 && data->x->ray >= 0)
		return (0);
	if (wall->side == 0 && data->x->ray < 0)
		return (1);
	if (wall->side == 1 && data->y->ray < 0)
		return (2);
	if (wall->side == 1 && data->y->ray >= 0)
		return (3);
	return (0);
}

void	vertical_line(int x, t_data *data, int texX, double step)
{
	int				y;
	t_wall			*wall;
	t_vtcln			vars;
	unsigned char	*buffer;

	wall = data->wall;
	wall->walltxtr = walltxtr_indentifier(data, wall);
	vars.pos = (wall->drawstart - HEIGHT / 2 + wall->line_height / 2) * step;
	y = wall->drawstart;
	buffer = (unsigned char *)mlx_get_data_addr(data->map->background.img,
			&data->map->background.bpp, &data->map->background.line_length,
			&data->map->background.endian);
	while (y <= wall->drawend)
	{
		vars.pixel = (y * data->map->background.line_length) + (x * 4);
		vars.texy = (int)vars.pos;
		vars.pos += step;
		vars.bits = -1;
		while (++vars.bits < 4)
			buffer[vars.pixel + vars.bits] = data->txtr[wall->walltxtr].addr
			[vars.texy * data->txtr[wall->walltxtr].line_length
				+ texX * 4 + vars.bits];
		y++;
	}
}
