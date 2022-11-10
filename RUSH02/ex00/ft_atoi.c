/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:41:21 by seycheon          #+#    #+#             */
/*   Updated: 2022/09/11 16:13:22 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

char	*ft_atoi(char *str)
{
	int				i;
	int				size;
	char			*arr;

	i = 0;
	size = 0;
	arr = NULL;
	while (is_space(*str))
		str++;
	if (*str >= '0' && *str <= '9')
	{
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		arr = (char *)malloc(sizeof(char) * (i + 1));
		i = 0;
		while (str[i] >= '0' && str[i] <= '9')
		{
			arr[i] = str[i];
			i++;
		}
		arr[i] = '\0';
	}
	return (arr);
}
