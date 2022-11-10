/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:24:47 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/06 22:09:28 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	g_l(char *str);
int	check_space(char str);
int	b_c(char *base, int len);
int	find_base(char *base, char c);
int	ft_atoi_base(char *str, char *base);

int	get_base_len(int num, char *base_to)
{
	int	count;
	int	base_len;

	base_len = g_l(base_to);
	count = 0;
	if (num < 0)
	{
		count += 1;
		num *= -1;
	}
	while (num / base_len != 0)
	{
		num /= base_len;
		count += 1;
	}
	return (count + 2);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{	
	long long	cache;
	char		*result;
	int			index;
	int			len;

	if (b_c(base_from, g_l(base_from)) || b_c(base_to, g_l(base_to)))
		return (0);
	cache = ft_atoi_base(nbr, base_from);
	index = get_base_len(cache, base_to);
	len = g_l(base_to);
	result = (char *)malloc(sizeof(char) * (index));
	result[--index] = '\0';
	if (cache <= 0)
	{	
		result[0] = '-';
		cache *= -1;
		if (cache == 0)
			result[0] = base_to[0];
	}
	while (cache != 0)
	{
		result[--index] = base_to[cache % len];
		cache = cache / len;
	}
	return (result);
}
