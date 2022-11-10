/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:47:05 by wyoon             #+#    #+#             */
/*   Updated: 2022/08/29 16:31:22 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hex_addr(unsigned long long addr, int count, char *hexcode)
{
	if (addr != 0)
	{
		hex_addr(addr / 16, count + 1, hexcode);
		write(1, &hexcode[addr % 16], 1);
	}
	else
	{
		while (count < 16)
		{
			write(1, "0", 1);
			count++;
		}
	}
}

void	print_hex_char(unsigned char *addr, int len, char *hexcode, char *str)
{
	int	index;

	index = 0;
	while (index < len)
	{
		if (index % 2 == 0)
			write(1, " ", 1);
		if (addr[index] >= ' ' && addr[index] <= '~')
			str[index] = addr[index];
		else
			str[index] = '.';
		write(1, &hexcode[addr[index] / 16], 1);
		write(1, &hexcode[addr[index] % 16], 1);
		index++;
	}
	while (index < 16)
	{
		if (index % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		index++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int		cache;
	int		pc;
	char	*hexcode;
	char	str[16];

	pc = 0;
	hexcode = "0123456789abcdef";
	while (size > 0)
	{	
		if (size > 16)
			cache = 16;
		else
			cache = size;
		hex_addr((unsigned long long)addr + pc, 0, hexcode);
		write(1, ":", 1);
		print_hex_char((unsigned char *)addr + pc, cache, hexcode, str);
		write(1, " ", 1);
		write(1, str, cache);
		write(1, "\n", 1);
		size -= cache;
		pc += 16;
	}
	return (addr);
}
