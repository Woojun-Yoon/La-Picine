/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:22:34 by wyoon             #+#    #+#             */
/*   Updated: 2022/08/29 16:31:24 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*hexcode;

	hexcode = "0123456789abcdef";
	while (*str != '\0')
	{
		if (*str <= 31 || *str >= 127)
		{
			write(1, "\\", 1);
			if (*str < 0)
			{
				i = (unsigned char)*str;
				write(1, &hexcode[i / 16], 1);
				write(1, &hexcode[i % 16], 1);
			}
			else
			{
				write(1, &hexcode[*str / 16], 1);
				write(1, &hexcode[*str % 16], 1);
			}
		}
		else
			write(1, str, 1);
		str++;
	}
}
