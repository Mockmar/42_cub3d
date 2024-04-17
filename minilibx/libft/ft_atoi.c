
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	long int	res;
	int			sign;
	char		*str;

	i = 0;
	res = 0;
	sign = 1;
	str = (char *)nptr;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1 * sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}
