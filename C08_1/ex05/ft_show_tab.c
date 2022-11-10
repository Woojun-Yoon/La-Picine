/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:37:42 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/08 16:00:14 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

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
		ft_putchar(num + '0');
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
			recur(nb);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;
	int	j;

	i = 0;
	while (par[i].str != '\0')
	{
		j = 0;
		while (par[i].str[j] != '\0')
			j++;
		write(1, par[i].str, j);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		j = 0;
		while (par[i].copy[j] != '\0')
			j++;
		write(1, par[i].copy, j);
		write(1, "\n", 1);
		i++;
	}
}
