#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "unistd.h"
#include <stdarg.h>

int ft_printf(char *str, ...);
int	ft_putstr(char *s);
int ft_putnbr(int n);
int ft_puthexa(int n, char a);
int	ft_putchar(char c);
int ft_putptr(void *b);

#endif