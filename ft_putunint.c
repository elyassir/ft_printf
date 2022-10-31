/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:16:45 by yel-mass          #+#    #+#             */
/*   Updated: 2022/10/31 10:16:56 by yel-mass         ###   ########.fr       */
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

static void	ft_putnbr_fd(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbr_fd(n / 10);
		ft_putchar(n % 10 + 48);
	}
	else
		ft_putchar(n + 48);
}

int ft_putunint(unsigned int n)
{
	ft_putnbr_fd(n);
	return (count_num(n));
}