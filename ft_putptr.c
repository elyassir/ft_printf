/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:03:36 by yel-mass          #+#    #+#             */
/*   Updated: 2022/11/01 17:13:41 by yel-mass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_num_hexa_ptr(unsigned long int nbr)
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

static int	ft_printhexa_ptr(unsigned long int i)
{
	if (i >= 16)
		ft_printhexa_ptr(i / 16);
	if (ft_putchar("0123456789abcdef"[i % 16]) < 0)
		return (-1);
	return (0);
}

int	ft_putptr(void *b)
{
	unsigned long int	a;

	a = (unsigned long int)b;
	if (ft_putstr("0x") < 0)
		return (-1);
	if (ft_printhexa_ptr(a) < 0)
		return (-1);
	return (2 + count_num_hexa_ptr(a));
}
