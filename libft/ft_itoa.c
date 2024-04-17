
#include "libft.h"

static int	ft_taille(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = -n;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_remplir(long int n, int taille, char *str)
{
	int	i;

	i = taille;
	if (n == 0)
		str[0] = '0';
	while (i >= 0 && n > 0)
	{
		str[i - 1] = n % 10 + 48;
		i--;
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	int		taille;
	char	*str;

	taille = ft_taille((long int)n);
	if (n < 0)
	{
		str = malloc(sizeof(*str) * taille + 2);
		if (!str)
			return (NULL);
		str[0] = '-';
		ft_remplir(-(long)n, taille, str + 1);
		str[taille + 1] = '\0';
	}
	else
	{
		str = malloc(sizeof(*str) * taille + 1);
		if (!str)
			return (NULL);
		ft_remplir((long)n, taille, str);
		str[taille] = '\0';
	}
	return (str);
}
