/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:03:40 by jehelee           #+#    #+#             */
/*   Updated: 2022/09/11 16:22:29 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*cat_string(char *str1, char *str2)
{
	unsigned int	i;
	char			*result;

	result = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!(result))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (*str1 != '\0')
	{
		result[i] = *str1;
		i++;
		str1++;
	}
	while (*str2 != '\0')
	{
		result[i] = *str2;
		i++;
		str2++;
	}
	result[i] = '\0';
	return (result);
}
