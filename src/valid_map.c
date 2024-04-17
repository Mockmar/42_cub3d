
#include "cub3d.h"

int	valid_upper_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_wall_space_newline(line[i]))
			return (printf("Error: walls not valid\n"), 0);
		i++;
	}
	return (1);
}

int	valid_lower_wall(t_data *data, char **position, int i, int j)
{
	j = 0;
	if (i == data->map->size)
	{
		while (position[i][j])
		{
			if (!is_wall_space_newline(position[i][j]))
				return (printf("Error: walls not valid\n"), 0);
			j++;
		}
	}
	return (1);
}

int	valid_map(char *line, t_data *data, int size)
{
	int	i;

	i = 0;
	data->map->size = size - 1;
	while (line[i] == ' ')
		i++;
	if (line[i] != '1')
		return (printf("Error: walls not valid\n"), 0);
	i++;
	while (line[i])
	{
		if (!is_wall_space_newline(line[i])
			&& line[i] != '0' && !is_pers(line[i]))
			return (printf("Error: map not valid\n"), 0);
		if (is_pers(line[i]))
			data->count->perso += 1;
		if (data->count->perso > 1)
			return (printf("Error: too many players\n"), 0);
		i++;
		if (line[i] == '\n' && line[i - 1] != '1')
			return (printf("Error: walls not valid\n"), 0);
	}
	return (1);
}

int	checking_empty_spots(char **position, int i, int j, t_data *data)
{
	j = 0;
	while (position[i][j])
	{
		if (is_pers(position[i][j]))
			init_pers(position, i, j, data);
		if (position[i][j] == '0' || is_pers(position[i][j]))
		{
			if (i > 0 && position[i - 1][j] != '1'
				&& position[i - 1][j] != '0' && !is_pers(position[i - 1][j]))
				return (printf("Error: walls not valid\n"), 0);
			if (i < data->map->size && position[i + 1][j] != '1'
				&& position[i + 1][j] != '0' && !is_pers(position[i + 1][j]))
				return (printf("Error: walls not valid\n"), 0);
			if (j > 0 && position[i][j - 1] != '1'
				&& position[i][j - 1] != '0' && !is_pers(position[i][j - 1]))
				return (printf("Error: walls not valid\n"), 0);
			if (j < (int)(ft_strlen(position[i])) && position[i][j + 1] != '1'
				&& position[i][j + 1] != '0' && !is_pers(position[i][j + 1]))
				return (printf("Error: walls not valid\n"), 0);
		}
		j++;
	}
	return (1);
}
