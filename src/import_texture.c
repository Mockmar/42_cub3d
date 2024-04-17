
#include "cub3d.h"

char	*copy_path_txtr(char *line, int i)
{
	char	*path_txtr;

	path_txtr = NULL;
	while (line[i])
	{
		if (line[i] && line[i] != ' ' && line[i] != '	' && line[i] != '\n')
		{
			path_txtr = ft_straddchar(path_txtr, line[i]);
			if (!path_txtr)
				return (NULL);
		}
		i++;
	}
	return (path_txtr);
}

int	get_path_txtr(char *line, t_data *data, int txtr_type, int start_copy)
{
	char	*path_txtr;

	path_txtr = NULL;
	path_txtr = copy_path_txtr(line, start_copy);
	if (!path_txtr)
		return (printf("Error load texture\n"), 1);
	else
	{
		data->txtr[txtr_type].img = mlx_xpm_file_to_image(data->mlx,
				path_txtr, &data->txtr[txtr_type].width,
				&data->txtr[txtr_type].height);
		free(path_txtr);
	}
	if (!data->txtr[txtr_type].img)
		return (printf("Error load texture\n"), 1);
	return (0);
}

int	ciel_floor(char *line, t_data *data)
{
	if (line[0] == 'F' && !check_colour(line, data))
		return (printf("Error: wrong colour\n"), 0);
	if (line[0] == 'C' && !check_colour(line, data))
		return (printf("Error: wrong colour\n"), 0);
	if (line[0] != '\n' && !is_pers(line[0])
		&& line[0] != 'F' && line[0] != 'C')
		return (printf("Error: wrong element\n"), 0);
	check_repetition(line[0], data);
	return (1);
}

void	get_texture_adress(t_data *data)
{
	data->txtr[0].addr = mlx_get_data_addr(data->txtr[0].img,
			&data->txtr[0].bpp,
			&data->txtr[0].line_length, &data->txtr[0].endian);
	data->txtr[1].addr = mlx_get_data_addr(data->txtr[1].img,
			&data->txtr[1].bpp,
			&data->txtr[1].line_length, &data->txtr[1].endian);
	data->txtr[2].addr = mlx_get_data_addr(data->txtr[2].img,
			&data->txtr[2].bpp,
			&data->txtr[2].line_length, &data->txtr[2].endian);
	data->txtr[3].addr = mlx_get_data_addr(data->txtr[3].img,
			&data->txtr[3].bpp,
			&data->txtr[3].line_length, &data->txtr[3].endian);
}
