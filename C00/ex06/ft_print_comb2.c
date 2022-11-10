/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 07:23:20 by wyoon             #+#    #+#             */
/*   Updated: 2022/08/27 14:51:46 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_char(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x <= 98)
	{
		y = x + 1;
		while (y <= 99)
		{
			ft_print_char((char)(x / 10 + 0x30));
			ft_print_char((char)(x % 10 + 0x30));
			ft_print_char(' ');
			ft_print_char((char)(y / 10 + 0x30));
			ft_print_char((char)(y % 10 + 0x30));
			if (x != 98)
			{
				ft_print_char(',');
				ft_print_char(' ');
			}
			y++;
		}
		x++;
	}
}

int main()
{
	ft_print_comb2();
	return 0;
}