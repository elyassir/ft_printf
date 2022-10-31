#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "unistd.h"
#include <stdarg.h>

int ft_printf(char **str, ...);
int	ft_putstr_fd(char *s, int fd);
int ft_putnbr(int n);
int ft_puthexa(int n, char a);
int	ft_putchar(char c);


#endif