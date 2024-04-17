
#include "cub3d.h"

int	tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	is_pers(char letter)
{
	if (letter == 'E' || letter == 'W' || letter == 'S' || letter == 'N')
		return (1);
	return (0);
}

int	is_wall_space_newline(char letter)
{
	if (letter == '1' || letter == ' ' || letter == '\n')
		return (1);
	return (0);
}

char	*skip_nl(char *line, int fd)
{
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

char	*ft_cut_beg(char *line, int beg)
{
	char	*str;
	int		j;

	str = malloc(sizeof(str) * (ft_strlen(line) - beg));
	if (!str)
		return (NULL);
	j = 0;
	while (line[beg])
	{
		str[j] = line[beg];
		beg++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
