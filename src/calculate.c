
#include "cub3d.h"

void	calculate_length_ray(t_data *data, double cameraX)
{
	t_x	*x;
	t_y	*y;

	x = data->x;
	y = data->y;
	x->ray = x->dir + x->plane * cameraX;
	y->ray = y->dir + y->plane * cameraX;
	x->map = x->pos;
	y->map = y->pos;
	x->delta_dist = sqrt(1 + (y->ray * y->ray) / (x->ray * x->ray));
	y->delta_dist = sqrt(1 + (x->ray * x->ray) / (y->ray * y->ray));
}

void	calculate_sidedist(t_data *data)
{
	t_x	*x;
	t_y	*y;

	x = data->x;
	y = data->y;
	if (x->ray < 0)
	{
		x->step = -1;
		x->side_dist = (x->pos - x->map) * x->delta_dist;
	}
	else
	{
		x->step = 1;
		x->side_dist = (x->map + 1.0 - x->pos) * x->delta_dist;
	}
	if (y->ray < 0)
	{
		y->step = -1;
		y->side_dist = (y->pos - y->map) * y->delta_dist;
	}
	else
	{
		y->step = 1;
		y->side_dist = (y->map + 1.0 - y->pos) * y->delta_dist;
	}
}

void	search_wall(t_data *data)
{	
	t_x	*x;
	t_y	*y;

	x = data->x;
	y = data->y;
	if (x->side_dist < y->side_dist)
	{
		x->side_dist += x->delta_dist;
		x->map += x->step;
		data->wall->side = 0;
	}
	else
	{
		y->side_dist += y->delta_dist;
		y->map += y->step;
		data->wall->side = 1;
	}
}

void	calculate_wall_height(t_data *data)
{
	t_wall	*wall;
	t_x		*x;
	t_y		*y;

	x = data->x;
	y = data->y;
	wall = data->wall;
	if (wall->side == 0)
		wall->perp_wall = (x->map - x->pos + (1 - x->step) / 2) / x->ray;
	else
		wall->perp_wall = (y->map - y->pos + (1 - y->step) / 2) / y->ray;
	wall->line_height = HEIGHT / wall->perp_wall;
	wall->drawstart = -wall->line_height / 2 + HEIGHT / 2;
	if (wall->drawstart < 0)
		wall->drawstart = 0;
	wall->drawend = wall->line_height / 2 + HEIGHT / 2;
	if (wall->drawend >= HEIGHT)
		wall->drawend = HEIGHT - 1;
}

int	calcul_xtxtr(t_data *data)
{
	double	wallx;
	t_wall	*wall;
	t_x		*x;
	t_y		*y;
	int		xtxtr;

	wall = data->wall;
	x = data->x;
	y = data->y;
	if (wall->side == 0)
		wallx = y->pos + wall->perp_wall * y->ray;
	else
		wallx = x->pos + wall->perp_wall * x->ray;
	wallx -= floor((wallx));
	xtxtr = (int)(wallx * (double)(DIM_TXTR));
	if (wall->side == 0 && x->ray > 0)
		xtxtr = DIM_TXTR - xtxtr - 1;
	if (wall->side == 1 && y->ray < 0)
		xtxtr = DIM_TXTR - xtxtr - 1;
	return (xtxtr);
}
