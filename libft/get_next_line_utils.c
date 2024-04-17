
#include "get_next_line.h"

size_t	ft_my_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*get_start(char *start, char *res, int *nl)
{
	free(res);
	res = ft_my_strdup(start);
	if (!res)
		return (NULL);
	*nl = ft_my_strchr(res, '\n');
	return (res);
}

int	ft_my_strchr(char *s, int c)
{
	int				i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (i);
		i++;
	}	
	if ((unsigned char)s[i] == (unsigned char)c)
		return (i);
	return (-1);
}

char	*ft_my_strjoin(char *s1, char *s2)
{
	int		i;
	char	*new;
	int		size;
	int		k;

	i = 0;
	k = ft_my_strlen(s1);
	size = k + ft_my_strlen(s2);
	new = malloc(sizeof (*new) * size + 1);
	if (new == NULL)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[i - k])
	{
		new[i] = s2[i - k];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_my_strdup(char *s)
{
	char	*new;
	int		i;
	int		len;

	i = 0;
	if (s == NULL)
		return (ft_my_strdup(""));
	len = ft_my_strlen(s);
	new = malloc(sizeof(*new) * len + 1);
	if (new == NULL)
		return (NULL);
	while (i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
