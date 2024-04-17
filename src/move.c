
#include "cub3d.h"

void	rotate(t_data *data)
{
	double	old_dir_x;
	double	plane_x;
	t_x		*x;
	t_y		*y;

	x = data->x;
	y = data->y;
	old_dir_x = x->dir;
	plane_x = x->plane;
	if (data->count->rotate_r == true)
	{
		x->dir = (x->dir * cos(-PI / 28)) - (y->dir * sin(-PI / 28));
		y->dir = (old_dir_x * sin(-PI / 28)) + (y->dir * cos(-PI / 28));
		x->plane = (x->plane * cos(-PI / 28)) - (y->plane * sin(-PI / 28));
		y->plane = (plane_x * sin(-PI / 28)) + (y->plane * cos(-PI / 28));
	}
	else if (data->count->rotate_l == true)
	{
		x->dir = (x->dir * cos(PI / 28)) - (y->dir * sin(PI / 28));
		y->dir = (old_dir_x * sin(PI / 28)) + (y->dir * cos(PI / 28));
		x->plane = (x->plane * cos(PI / 28)) - (y->plane * sin(PI / 28));
		y->plane = (plane_x * sin(PI / 28)) + (y->plane * cos(PI / 28));
	}
}

void	move_left_right(t_data *data)
{
	t_x		*x;
	t_y		*y;

	x = data->x;
	y = data->y;
	if (data->count->a == true)
	{
		if (data->map->map[(int)(y->pos - x->dir * 0.2)][(int)(x->pos)] != '1')
			y->pos -= x->dir * 0.2;
		if (data->map->map[(int)y->pos][(int)(x->pos + y->dir * 0.2)] != '1')
			x->pos += y->dir * 0.2;
	}
	if (data->count->d == true)
	{
		if (data->map->map[(int)(y->pos + x->dir * 0.2)][(int)x->pos] != '1')
			y->pos += x->dir * 0.2;
		if (data->map->map[(int)y->pos][(int)(x->pos - y->dir * 0.2)] != '1')
			x->pos -= y->dir * 0.2;
	}
}

void	move_up_down(t_data *data)
{
	t_x		*x;
	t_y		*y;

	x = data->x;
	y = data->y;
	if (data->count->w == true)
	{
		if (data->map->map[(int)(y->pos + y->dir * 0.2)][(int)x->pos] != '1')
			y->pos += y->dir * 0.2;
		if (data->map->map[(int)y->pos][(int)(x->pos + x->dir * 0.2)] != '1')
			x->pos += x->dir * 0.2;
	}
	if (data->count->s == true)
	{
		if (data->map->map[(int)(y->pos - y->dir * 0.2)][(int)x->pos] != '1')
			y->pos -= y->dir * 0.2;
		if (data->map->map[(int)y->pos][(int)(x->pos - x->dir * 0.2)] != '1')
			x->pos -= x->dir * 0.2;
	}
}
