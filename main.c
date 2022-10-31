#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
int main()
{
    ft_printf("%d\n", ft_printf(" %d ", INT_MIN));
    printf("%d\n", printf(" %d ", INT_MIN));
    //printf("%d", -10);
}