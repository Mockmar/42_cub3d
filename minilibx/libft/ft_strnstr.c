
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	k;
	char	*large;	
	char	*small;

	large = (char *)big;
	small = (char *)little;
	i = 0;
	if (small[0] == 0)
		return (large);
	while (large[i] && (i + ft_strlen(small)) <= n)
	{
		k = 0;
		while (small[k] == large[i + k] && small[k])
		{
			if (small[k + 1] == 0)
				return (large + i);
			k++;
		}
		i++;
	}
	return (0);
}
