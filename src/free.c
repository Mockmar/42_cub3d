
#include "cub3d.h"

void	my_free(t_data *data)
{
	free_map(data);
	free(data->mlx);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->map->size && data->map->map)
		free(data->map->map[i++]);
	free(data->map->map);
}

void	free_tab(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_xpm_ptr(t_data *data)
{
	if (data->txtr[0].img)
		mlx_destroy_image(data->mlx, data->txtr[0].img);
	if (data->txtr[1].img)
		mlx_destroy_image(data->mlx, data->txtr[1].img);
	if (data->txtr[2].img)
		mlx_destroy_image(data->mlx, data->txtr[2].img);
	if (data->txtr[3].img)
		mlx_destroy_image(data->mlx, data->txtr[3].img);
}
