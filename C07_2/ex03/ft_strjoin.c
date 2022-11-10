/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:34:15 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/07 17:05:36 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_len1(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		all_len;
	int		i;
	char	*result;

	all_len = get_len1(strs[0]);
	i = 1;
	while (i < size)
	{
		all_len += get_len1(sep);
		all_len += get_len1(strs[i]);
		i++;
	}
	result = (char *)malloc(sizeof(char) * (all_len + 1));
	result[0] = '\0';
	i = 0;
	while (i < size)
	{
		result = ft_strcat(result, strs[i]);
		if (i != size - 1)
			result = ft_strcat(result, sep);
		i++;
	}
	return (result);
}
