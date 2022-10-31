/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:03:36 by yel-mass          #+#    #+#             */
/*   Updated: 2022/10/31 10:03:54 by yel-mass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static int	count_num_hexa_ptr(size_t nbr)
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

static void ft_printhexa_ptr(size_t i)
{
    if (i >= 16)
        ft_printhexa(i / 16);
    ft_putchar("0123456789abcdef"[i % 16]);
}

int ft_putptr(int n, char a)
{
	ft_printhexa_ptr(n);
	return (count_num_hexa_ptr(n));
}
