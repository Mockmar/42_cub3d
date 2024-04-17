
#include "cub3d.h"

int	check_before_path(char *line, int i)
{
	while (line[i] == ' ')
		i++;
	if (line[i] != '.' && line[i + 1] != '/')
		return (0);
	return (1);
}

char	*path_texture(char *line)
{
	int		i;
	char	*path;

	i = 0;
	while (line[i] != '/')
		i++;
	i++;
	path = ft_cut_beg(line, i);
	return (path);
}

void	check_repetition(char first, t_data *data)
{
	if (first == 'E')
		data->count->east += 1;
	if (first == 'W')
		data->count->west += 1;
	if (first == 'N')
		data->count->north += 1;
	if (first == 'S')
		data->count->south += 1;
	if (first == 'F')
		data->count->floor += 1;
	if (first == 'C')
		data->count->ceiling += 1;
}

int	check_txtr(char *line, char first, char second)
{
	int	i;

	i = 0;
	if (line[0] == first)
	{
		if (line[1] != second && line[1] != ' ')
			return (0);
	}
	if (line[1] == ' ')
	{
		i = 1;
		if (check_before_path(line, i) == 0)
			return (0);
	}
	if (line[1] == second)
	{
		if (line[2] != ' ')
			return (0);
		i = 2;
		if (check_before_path(line, i) == 0)
			return (0);
		return (2);
	}
	return (1);
}
