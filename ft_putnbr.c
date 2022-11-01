/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:27:49 by yel-mass          #+#    #+#             */
/*   Updated: 2022/11/01 15:49:00 by yel-mass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_num(int nbr)
{
	int	count;

	count = 1;
	if (nbr < 0)
	{
		if (nbr == -2147483648)
			return (11);
		nbr *= -1;
		count++;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

static int	ft_putnbr_fd(int n)
{
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) < 0)
			return (-1);
		return (0);
	}
	if (n < 0)
	{
		if (ft_putchar('-') < 0)
			return (-1);
		if (ft_putnbr_fd(-n) < 0)
			return (-1);
	}
	else if (n > 9)
	{
		if (ft_putnbr_fd(n / 10) < 0)
			return (-1);
		if (ft_putchar(n % 10 + 48) < 0)
			return (-1);
	}
	else
		if (ft_putchar(n + 48) < 0)
			return (-1);
	return (0);
}

int	ft_putnbr(int n)
{
	if (ft_putnbr_fd(n) < 0)
		return (-1);
	return (count_num(n));
}
