/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:27:49 by yel-mass          #+#    #+#             */
/*   Updated: 2022/10/31 09:29:10 by yel-mass         ###   ########.fr       */
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

static void	ft_putnbr_fd(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr_fd(-n);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10);
		ft_putchar(n % 10 + 48);
	}
	else
		ft_putchar(n + 48);
}

int ft_putnbr(int n)
{
	ft_putnbr_fd(n);
	return (count_num(n));
}