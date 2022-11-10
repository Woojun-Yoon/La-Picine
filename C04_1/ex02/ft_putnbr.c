/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:37:32 by wyoon             #+#    #+#             */
/*   Updated: 2022/08/31 23:06:44 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	recur(int num)
{
	if (num > 9)
	{
		recur(num / 10);
		recur(num % 10);
	}
	else
	{
		ft_putchar(num + '0');
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		recur(147483648);
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= -1;
			recur(nb);
		}
		else
		{
			recur(nb);
		}
	}
}
