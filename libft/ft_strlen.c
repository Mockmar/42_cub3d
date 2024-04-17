
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
