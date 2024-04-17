
#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (-1);
}

int	ft_putnbr_u(unsigned int nb)
{
	int			i;

	i = 0;
	if (nb < 10)
	{
		nb = nb + '0';
		write(1, &nb, 1);
		i++;
	}
	else
	{
		i += ft_putnbr_u(nb / 10);
		i += ft_putnbr_u(nb % 10);
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long long	nb;
	int			i;

	nb = n;
	i = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		i++;
	}
	if (nb < 10)
	{
		nb = nb + '0';
		write(1, &nb, 1);
		i++;
	}
	else
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (4);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i - 2);
}

int	ft_putnbr_hex_maj(unsigned int nbr)
{
	long long	n;
	char		*base;
	int			i;

	base = "0123456789ABCDEF";
	n = nbr;
	i = 0;
	if (n < 16)
	{
		ft_putchar(base[n]);
		i++;
	}
	else
	{
		i += ft_putnbr_hex_maj(n / 16);
		i += ft_putnbr_hex_maj(n % 16);
	}
	return (i);
}
