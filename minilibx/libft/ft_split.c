#include "libft.h"

int	num_of_word(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

char	*ft_strcpy(char *str, int pos_init, int pos_fin)
{
	char	*tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(*tab) * (pos_fin - pos_init) + 1);
	if (!tab)
		return (NULL);
	while (pos_init < pos_fin)
	{
		tab[i] = str[pos_init];
		pos_init++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_make_tab(char *str, char c, char **tab, int i)
{
	int	pos_init;
	int	word;

	word = 0;
	while (str[i])
	{
		pos_init = i;
		while (str[i] != c && str[i])
			i++;
		tab[word++] = ft_strcpy(str, pos_init, i);
		while (str[i] == c && str[i])
			i++;
	}
	tab[word] = 0;
	return (tab);
}

char	**ft_split(const char *str, char c)
{
	char	**tab;
	int		i;

	i = 0;
	while (str[0] && str[0] == c)
		str++;
	tab = malloc(sizeof(*tab) * ((num_of_word((char *)str, c) + 1)));
	if (tab == NULL)
		return (NULL);
	tab = ft_make_tab((char *)str, c, tab, i);
	return (tab);
}
