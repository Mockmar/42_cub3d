
#include "cub3d.h"

int	key_press(int key_code, t_data *data)
{
	if (key_code == 65307)
		mlx_loop_end(data->mlx);
	if (key_code == 'a')
		data->count->a = true;
	if (key_code == 'd')
		data->count->d = true;
	if (key_code == 'w')
		data->count->w = true;
	if (key_code == 's')
		data->count->s = true;
	if (key_code == 65361)
		data->count->rotate_r = true;
	if (key_code == 65363)
		data->count->rotate_l = true;
	return (0);
}

int	key_release(int key_code, t_data *data)
{
	if (key_code == 'a')
		data->count->a = false;
	if (key_code == 'd')
		data->count->d = false;
	if (key_code == 'w')
		data->count->w = false;
	if (key_code == 's')
		data->count->s = false;
	if (key_code == 65361)
		data->count->rotate_r = false;
	if (key_code == 65363)
		data->count->rotate_l = false;
	return (0);
}

void	init_key(t_data *data)
{
	data->count->a = false;
	data->count->d = false;
	data->count->s = false;
	data->count->w = false;
	data->count->rotate_r = false;
	data->count->rotate_l = false;
}
