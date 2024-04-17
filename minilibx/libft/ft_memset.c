
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	a;
	unsigned char	*str;

	a = (unsigned char)c;
	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = a;
		i++;
	}
	return (b);
}
