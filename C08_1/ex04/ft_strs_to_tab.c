/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:48:31 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/08 16:00:11 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	get_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		index;

	dest = malloc(sizeof(char) * (get_len(src) + 1));
	if (!dest)
		return (0);
	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*result;
	int				index;

	index = 0;
	result = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!(result))
		return (0);
	while (index < ac && av[index] != '\0')
	{
		result[index].size = get_len(av[index]);
		result[index].str = av[index];
		result[index].copy = ft_strdup(av[index]);
		index++;
	}
	result[index].size = 0;
	result[index].str = 0;
	result[index].copy = 0;
	return (result);
}
