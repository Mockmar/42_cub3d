
#include "cub3d.h"

int	checking_longer_lines(char **position, int i, int j)
{
	j = 0;
	if (ft_strlen(position[i]) < ft_strlen(position[i + 1]))
	{
		j = ft_strlen(position[i]) - 1;
		while (position[i + 1][j])
		{
			if (position[i + 1][j] != '\n' && position[i + 1][j] != '1'
				&& position[i + 1][j] != ' ' && !is_pers(position[i][j]))
				return (printf("Error: walls not valid\n"), 0);
			j++;
		}
	}
	if (ft_strlen(position[i]) > ft_strlen(position[i + 1]))
	{
		j = ft_strlen(position[i + 1]) - 1;
		while (position[i][j])
		{
			if (position[i][j] != '\n' && position[i][j] != '1'
				&& position[i][j] != ' ' && !is_pers(position[i][j]))
				return (printf("Error: walls not valid\n"), 0);
			j++;
		}
	}
	return (1);
}

int	valid_map2(t_data *data, int size)
{
	int	i;
	int	j;

	i = 0;
	if (size < 2)
		return (printf("Error: map size of 1\n"), 0);
	while (data->map->map[i] && i < data->map->size)
	{
		j = 0;
		if (checking_empty_spots(data->map->map, i, j, data) == 0
			|| checking_longer_lines(data->map->map, i, j) == 0)
			return (0);
		i++;
	}
	if (valid_lower_wall(data, data->map->map, i, j) == 0)
		return (0);
	if (data->count->perso != 1)
		return (printf("Error: there is no player\n"), 0);
	return (1);
}

int	read_map(int fd, t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	data->map->size = 0;
	line = get_next_line(fd);
	line = skip_nl(line, fd);
	if (!line)
		return (printf("Error: no map\n"), 0);
	if (valid_upper_wall(line) == 0)
		return (free(line), 0);
	while (line)
	{
		if (valid_map(line, data, i) == 0)
			return (free(line), 0);
		data->map->map = ft_tabaddstr(data->map->map, line);
		if (!data->map->map)
			return (free(line), 0);
		line = get_next_line(fd);
		i++;
	}
	data->map->size = i - 1;
	if (valid_map2(data, i) == 0)
		return (0);
	return (1);
}
