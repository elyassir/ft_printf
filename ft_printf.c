/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:10:44 by yel-mass          #+#    #+#             */
/*   Updated: 2022/11/03 15:46:30 by yel-mass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(va_list arg, char format)
{
	int	ret;

	ret = 0;
	if (format == 'c')
		ret = ft_putchar(va_arg(arg, int));
	else if (format == 's')
		ret = ft_putstr(va_arg(arg, char *));
	else if (format == 'i' || format == 'd')
		ret = ft_putnbr(va_arg(arg, int));
	else if (format == 'p')
		ret = ft_putptr(va_arg(arg, void *));
	else if (format == 'x' || format == 'X')
		ret = ft_puthexa(va_arg(arg, int), format);
	else if (format == 'u')
		ret = ft_putunint(va_arg(arg, unsigned int));
	else if (format == '%')
		ret = ft_putchar('%');
	else
		ret = ft_putchar(format);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	int		ret2;
	va_list	ptr;

	i = 0;
	ret = 0;
	va_start(ptr, str);
	while (str[i])
	{
		while (str[i] != '%' && str[i] != '\0' && ret++ != -1)
			if (ft_putchar(str[i++]) < 0)
				return (-1);
		ret2 = ret;
		if (str[i] == '\0' || str[i + 1] == '\0')
			return (ret);
		ret += check(ptr, str[i + 1]);
		if (ret2 > ret)
			return (-1);
		i += 2;
	}
	va_end(ptr);
	return (ret);
}
