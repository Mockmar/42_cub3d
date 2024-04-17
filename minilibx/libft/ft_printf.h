#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <string.h>

int	ft_putchar(char c);
int	ft_putnbr_u(unsigned int n);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_putnbr_hex_maj(unsigned int nbr);
int	ft_putnbr_hex_m(unsigned long long n);
int	ft_printf(const char *s, ...);

#endif 
