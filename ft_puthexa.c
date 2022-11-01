/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:47:56 by yel-mass          #+#    #+#             */
/*   Updated: 2022/11/01 17:13:01 by yel-mass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_num_hexa(unsigned int nbr)
{
	int	count;

	count = 1;
	while (nbr >= 16)
	{
		nbr = nbr / 16;
		count++;
	}
	return (count);
}

static int	ft_printhexa_fd(unsigned int i, char a)
{
	if (i >= 16)
		if (ft_printhexa_fd(i / 16, a) < 0)
			return (-1);
	if (a == 'x')
	{
		if (ft_putchar("0123456789abcdef"[i % 16]) < 0)
			return (-1);
	}
	else if (a == 'X')
	{
		if (ft_putchar("0123456789ABCDEF"[i % 16]) < 0)
			return (-1);
	}
	return (0);
}

int	ft_puthexa(int n, char a)
{
	if (ft_printhexa_fd(n, a) < 0)
		return (-1);
	return (count_num_hexa(n));
}
