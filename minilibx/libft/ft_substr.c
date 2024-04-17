
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	i = 0;
	if (ft_strlen(s) <= start)
		return (ft_calloc(1, 1));
	if (ft_strlen(s + start) > len)
		new = malloc(sizeof(*new) * (len) + 1);
	else
		new = malloc(ft_strlen(s + start) + 1);
	if (new == NULL)
		return (NULL);
	while (s[i + start] && i < len)
	{
		new[i] = s[i + start];
		i++;
	}
	new[i] = '\0';
	return (new);
}
