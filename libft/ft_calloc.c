
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t n)
{
	char	*tab;

	if (n == 0 || nmemb == 0)
	{
		n = 1;
		nmemb = 1;
	}
	tab = malloc((nmemb * n));
	if (tab != NULL)
		ft_bzero(tab, nmemb * n);
	return (tab);
}
