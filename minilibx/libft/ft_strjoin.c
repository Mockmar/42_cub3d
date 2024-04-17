
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*new;
	int		size;
	int		k;

	i = 0;
	k = ft_strlen(s1);
	size = k + ft_strlen(s2);
	new = malloc(sizeof (*new) * size + 1);
	if (new == NULL)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[i - k])
	{
		new[i] = s2[i - k];
		i++;
	}
	new[i] = '\0';
	return (new);
}
