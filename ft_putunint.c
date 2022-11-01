/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:16:45 by yel-mass          #+#    #+#             */
/*   Updated: 2022/11/01 18:32:24 by yel-mass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_num(unsigned int nbr)
{
	int	count;

	count = 1;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

static int	ft_putnbr_fd(unsigned int n)
{
	if (n > 9)
	{
		if (ft_putnbr_fd(n / 10) < 0)
			return (-1);
		if (ft_putchar(n % 10 + 48) < 0)
			return (-1);
	}
	else
	{
		if (ft_putchar(n + 48) < 0)
			return (-1);
	}
	return (0);
}

int	ft_putunint(unsigned int n)
{
	if (ft_putnbr_fd(n) < 0)
		return (-1);
	return (count_num(n));
}
