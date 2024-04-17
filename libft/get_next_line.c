#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 2048

int	read_line(int fd, char *s)
{
	ssize_t		read_bytes;

	read_bytes = read(fd, s, BUFFER_SIZE);
	if (read_bytes <= 0)
		return (read_bytes);
	s[read_bytes] = '\0';
	return (1);
}

char	*cut_end(char *res, int nl_position)
{
	char	*end;
	int		i;
	int		end_len;

	i = 0;
	end_len = nl_position + 1;
	end = malloc(end_len + 1);
	if (end == NULL)
		return (NULL);
	while (i <= nl_position)
	{
		end[i] = res[i];
		i++;
	}
	end[i] = '\0';
	free(res);
	return (end);
}

char	*cut_start(char *res, int nl_position, char *start)
{
	int		i;
	int		start_len;

	i = 0;
	if (!res)
		return (NULL);
	start_len = (ft_strlen(res) - nl_position) - 1;
	if (start_len < 0)
		return (NULL);
	while (i < start_len)
	{
		start[i] = res[i + nl_position + 1];
		i++;
	}
	start[i] = '\0';
	return (start);
}

char	*return_line(int fd, char *buffer_save, int nl, char *res)
{
	int			error;
	static char	start[BUFFER_SIZE + 1];

	if (start[0] != '\0' && *res == '\0')
		res = get_start(start, res, &nl);
	if (!res)
		return (NULL);
	while (nl == -1)
	{
		error = read_line(fd, buffer_save);
		if (error <= 0)
			break ;
		res = ft_my_strjoin(res, buffer_save);
		if (!res)
			return (NULL);
		nl = ft_my_strchr(res, '\n');
	}
	free(buffer_save);
	if (nl == -1)
		nl = ft_my_strlen(res) - 1;
	cut_start(res, nl, start);
	if (nl >= 0)
		res = cut_end(res, nl);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*buffer_save;
	char		*res;

	res = ft_my_strdup("");
	if (!res)
		return (NULL);
	buffer_save = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	if (buffer_save == NULL)
		return (NULL);
	res = return_line(fd, buffer_save, -1, res);
	if (res && ft_my_strlen(res) == 0)
	{
		free(res);
		res = NULL;
	}
	return (res);
}
