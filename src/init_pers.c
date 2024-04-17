
#include "cub3d.h"

void	north_south_direction(char letter, t_data *data)
{
	if (letter == 'N')
	{
		data->x->dir = 0;
		data->y->dir = -1;
		data->x->plane = 0.66;
		data->y->plane = 0;
	}
	else if (letter == 'S')
	{
		data->x->dir = 0;
		data->y->dir = 1;
		data->x->plane = -0.66;
		data->y->plane = 0;
	}
}

void	east_west_direction(char letter, t_data *data)
{
	if (letter == 'E')
	{
		data->x->dir = 1;
		data->y->dir = 0;
		data->x->plane = 0;
		data->y->plane = 0.66;
	}
	else if (letter == 'W')
	{
		data->x->dir = -1;
		data->y->dir = 0;
		data->x->plane = 0;
		data->y->plane = -0.66;
	}
}

void	init_pers(char **position, int i, int j, t_data *data)
{
	t_x	*x;
	t_y	*y;

	x = data->x;
	y = data->y;
	y->pos = (double)(i) + 0.5;
	x->pos = (double)(j) + 0.5;
	north_south_direction(position[i][j], data);
	east_west_direction(position[i][j], data);
}
