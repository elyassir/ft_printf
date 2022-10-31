/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:47:56 by yel-mass          #+#    #+#             */
/*   Updated: 2022/10/31 09:48:11 by yel-mass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

static void ft_printhexa(unsigned int i, char a)
{
    if (i >= 16)
        ft_printhexa(i / 16, a);
    if (a == 'x')
        ft_putchar("0123456789abcdef"[i % 16]);
    else if (a == 'X')
        ft_putchar("0123456789ABCDEF"[i % 16]);
}

int ft_puthexa(int n, char a)
{
	ft_printhexa(n, a);
	return (count_num_hexa(n));
}

