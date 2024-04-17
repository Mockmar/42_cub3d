#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "ft_printf.h"
#include "libft.h"

int	ft_putnbr_hex_x(unsigned int n)
{
	char		*base;
	int			i;

	base = "0123456789abcdef";
	i = 0;
	if (n < 16)
	{
		ft_putchar(base[n]);
		i++;
	}
	else
	{
		i += ft_putnbr_hex_x(n / 16);
		i += ft_putnbr_hex_x(n % 16);
	}
	return (i);
}

int	ft_putnbr_hex_m(unsigned long long n)
{
	char		*base;
	int			i;

	base = "0123456789abcdef";
	i = 0;
	if (n < 16)
	{
		ft_putchar(base[n]);
		i++;
	}
	else
	{
		i += ft_putnbr_hex_m(n / 16);
		i += ft_putnbr_hex_m(n % 16);
	}
	return (i);
}

int	ft_putnbr_hex_p(unsigned long long n)
{
	char		*base;
	int			i;

	base = "0123456789abcdef";
	i = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (2);
	}
	write(1, "0x", 2);
	if (n < 16)
	{
		ft_putchar(base[n]);
		i++;
	}
	else
	{
		i += ft_putnbr_hex_m(n / 16);
		i += ft_putnbr_hex_m(n % 16);
	}
	return (i);
}

int	check_conv(va_list lparam, char c)
{
	unsigned int	res;

	res = 0;
	if (c == 'c')
		res = ft_putchar(va_arg(lparam, int));
	else if (c == 'd' || c == 'i')
		res = ft_putnbr(va_arg(lparam, unsigned long)) - 2;
	else if (c == 'u')
		res = ft_putnbr_u(va_arg(lparam, unsigned long)) - 2;
	else if (c == 's')
		res = ft_putstr(va_arg(lparam, char *));
	else if (c == 'X')
		res = ft_putnbr_hex_maj(va_arg(lparam, int)) - 2;
	else if (c == 'x')
		res = ft_putnbr_hex_x(va_arg(lparam, unsigned int)) - 2;
	else if (c == '%')
		res = ft_putchar('%');
	else if (c == 'p')
		res = ft_putnbr_hex_p(va_arg(lparam, unsigned long long));
	return (res);
}

int	ft_printf(const char *s, ...)
{
	va_list			lparam;
	int				i;
	unsigned int	res;

	res = ft_strlen(s);
	va_start(lparam, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && (s[i + 1] == 'c' || s[i + 1] == 's'
				|| s[i + 1] == 'd' || s[i + 1] == 'i' || s[i + 1] == 'u'
				|| s[i + 1] == 'x' || s[i + 1] == 'X' || s[i + 1] == '%'
				|| s[i + 1] == 'p'))
		{
			res += check_conv(lparam, s[i + 1]);
			i += 2;
		}
		else
			write(1, &s[i++], 1);
	}
	va_end(lparam);
	return (res);
}
