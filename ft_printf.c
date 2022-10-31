#include "ft_printf.h"
#include <limits.h>
int ft_printf(const char *str, ...)
{
    int i;
    int ret;
    va_list ptr;

    i = 0;
    ret = 0;
    va_start(ptr, str);
    while (str[i])
    {
        while (str[i] != '%' && str[i] != '\0')
            ret += ft_putchar(str[i++]);
        if (str[i] == '\0')
            return (ret);
        if (str[i + 1] == 'c')
            ret += ft_putchar(va_arg(ptr, int));
        else if (str[i + 1] == 's')
            ret += ft_putstr(va_arg(ptr, char *));
        else if (str[i + 1] == 'i' || str[i + 1] == 'd')
            ret += ft_putnbr(va_arg(ptr, int));
        else if (str[i + 1] == 'p')
            ret += ft_putptr(va_arg(ptr, void *));
        else if (str[i + 1] == 'x' || str[i + 1] == 'X')
            ret += ft_puthexa(va_arg(ptr, int), str[i + 1]);
        else if (str[i + 1] == 'u')
            ret += ft_putunint(va_arg(ptr, unsigned int));
        else if (str[i + 1] == '%')
            ret += ft_putchar('%');
        i += 2;
    }
    va_end(ptr);
    return (ret);
}
