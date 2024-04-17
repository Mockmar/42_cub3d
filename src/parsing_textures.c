
#include "cub3d.h"

void	store_colours(char colour, int j, int c, t_data *data)
{
	if (colour == 'C')
	{
		if (j == 0)
			data->ceiling->r = c;
		if (j == 1)
			data->ceiling->g = c;
		if (j == 2)
			data->ceiling->b = c;
	}
	if (colour == 'F')
	{
		if (j == 0)
			data->floor->r = c;
		if (j == 1)
			data->floor->g = c;
		if (j == 2)
			data->floor->b = c;
	}
}

int	iscolour(char *colours)
{
	int	i;

	i = 0;
	while (colours[i])
	{
		if (!ft_isdigit(colours[i]) && colours[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_colour(char *line, t_data *data)
{
	int		i;
	int		j;
	char	**colours;
	char	*tmp;
	int		c;

	i = 1;
	if (line[i] != ' ')
		return (0);
	while (line[i] == ' ')
		i++;
	tmp = ft_cut_beg(line, i);
	colours = ft_split(tmp, ',');
	j = 0;
	while (colours[j] && j < 3)
	{
		c = ft_atoi(colours[j]);
		if (c > 255 || c < 0 || tab_size(colours) != 3 || !iscolour(colours[j]))
			return (free(tmp), free_tab(colours, tab_size(colours)), 0);
		store_colours(line[0], j, c, data);
		j++;
	}
	free(tmp);
	free_tab(colours, j);
	return (1);
}

int	textures(char *line, t_data *data)
{
	if (line[0] == 'E' && check_txtr(line, 'E', 'A') > 0 && !data->count->east)
		if (get_path_txtr(line, data, 0, check_txtr(line, 'E', 'A')))
			return (0);
	if (line[0] == 'E' && check_txtr(line, 'E', 'A') == 0)
		return (printf("wrong east texture\n"), 0);
	if (line[0] == 'W' && check_txtr(line, 'W', 'E') > 0 && !data->count->west)
		if (get_path_txtr(line, data, 1, check_txtr(line, 'W', 'E')))
			return (0);
	if (line[0] == 'W' && check_txtr(line, 'W', 'E') == 0)
		return (printf("wrong west texture\n"), 0);
	if (line[0] == 'S' && check_txtr(line, 'S', 'O') > 0 && !data->count->south)
		if (get_path_txtr(line, data, 3, check_txtr(line, 'S', 'O')))
			return (0);
	if (line[0] == 'S' && check_txtr(line, 'S', 'O') == 0)
		return (printf("wrong south texture\n"), 0);
	if (line[0] == 'N' && check_txtr(line, 'N', 'O') > 0 && !data->count->north)
		if (get_path_txtr(line, data, 2, check_txtr(line, 'N', 'O')))
			return (0);
	if (line[0] == 'N' && check_txtr(line, 'N', 'O') == 0)
		return (printf("wrong north texture\n"), 0);
	return (ciel_floor(line, data));
}

int	read_textures(int fd, t_data *data)
{
	char	*line;	

	line = get_next_line(fd);
	if (line == NULL)
		return (printf("Error: empty file\n"), 0);
	while (line)
	{
		line = skip_nl(line, fd);
		if (!line)
			return (printf("Error: not enough element\n"), 0);
		if (!textures(line, data))
			return (free(line), 0);
		free(line);
		if (data->count->east == 1 && data->count->west == 1
			&& data->count->ceiling == 1 && data->count->north == 1
			&& data->count->floor == 1 && data->count->south == 1)
			break ;
		line = get_next_line(fd);
	}
	if (!data->txtr[0].img || !data->txtr[1].img
		|| !data->txtr[2].img || !data->txtr[3].img)
		return (printf("Error: not enough texture\n"), 0);
	if (read_map(fd, data) == 0)
		return (free_map(data), 0);
	return (1);
}
