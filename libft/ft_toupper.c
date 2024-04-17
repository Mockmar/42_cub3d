
#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	if (a >= 'a' && a <= 'z')
		a -= 32;
	return (a);
}
