
#include "cub3d.h"

static char	*if_strempty(char c)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = 0;
	return (str);
}

char	*ft_straddchar(char *s1, char c)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	if (!s1)
		return (if_strempty(c));
	len = ft_strlen(s1) + 1;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = 0;
	free(s1);
	return (str);
}

int	skip_ws(char *line, int i)
{
	while (line[i] && (line[i] == ' ' || line[i] == '	'))
		i++;
	return (i);
}

static char	**if_tabempty(char *str)
{
	char	**tab;

	tab = malloc(sizeof(*tab) * 2);
	if (!tab)
		return (NULL);
	tab[0] = str;
	tab[1] = NULL;
	return (tab);
}

char	**ft_tabaddstr(char **t1, char *str)
{
	int		i;
	int		len;
	char	**tab;

	i = 0;
	if (!t1)
		return (if_tabempty(str));
	len = tab_size(t1) + 1;
	tab = malloc(sizeof(*tab) * (len + 1));
	if (!tab)
		return (NULL);
	while (t1 && t1[i])
	{
		tab[i] = ft_strdup(t1[i]);
		i++;
	}
	tab[i] = str;
	tab[i + 1] = NULL;
	free_tab(t1, len);
	return (tab);
}
