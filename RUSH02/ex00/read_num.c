/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:23:47 by seycheon          #+#    #+#             */
/*   Updated: 2022/09/11 20:05:18 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	len_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	fill_arr(char *dest, int i, int size)
{
	int	j;

	dest[0] = '1';
	j = 1;
	while (j < size - i)
	{
		dest[j] = '0';
		j++;
	}
	dest[j] = '\0';
}

int	size_of_arr(char *str, int size)
{
	int	i;
	int	return_size;

	i = 0;
	return_size = 0;
	while (i < size)
	{
		if ((size - (i + 1)) % 3 == 0 && (size - i != 1))
		{
			if (str[size - i] != '0')
				return_size += 1;
			if (!(i == 0 && str[size - i] == '0'))
				return_size += 1;
		}
		else if ((size - (i + 1)) % 3 == 2 && str[size - i] != '0')
			return_size += 2;
		else if ((size - (i + 1)) % 3 == 1 && str[size - i] == '1')
		{
			return_size += 1;
			if ((size - (i + 2)) % 3 != 0)
				i += 2;
			else
				i += 1;
			continue ;
		}
		else if ((size - (i + 1)) % 3 == 1 && str[size - i] != '0')
			return_size += 1;
		else if ((size - (i + 1)) % 3 == 0 && str[size - i] != '0' \
		&& (size - i == 1))
			return_size += 1;
		i++;
	}
	return (return_size);
}

void	malloc_arr(char **arr, char *str, int size, int i)
{
	int	j;
	int	flag;

	j = 0;
	while (i < size)
	{
		if ((size - (i + 1)) % 3 == 0 && (size - i != 1))
		{
			flag = 0;
			if (i > 0 && str[i - 1] == '1')
				flag = 1;
			if (flag == 0 && str[i] != '0')
			{
				arr[j] = (char *)malloc(sizeof(char) * 2);
				arr[j][0] = str[i];
				arr[j][1] = '\0';
				j++;
			}
			if (!(i == 0 && str[i] == '0'))
			{
				arr[j] = (char *)malloc(sizeof(char) * (size - i + 1));
				fill_arr(arr[j], i, size);
				j++;
			}	
		}
		else if ((size - (i + 1)) % 3 == 2 && str[i] != '0')
		{
			arr[j] = (char *)malloc(sizeof(char) * 2);
			arr[j][0] = str[i];
			arr[j][1] = '\0';
			j++;
			arr[j] = (char *)malloc(sizeof(char) * 4);
			fill_arr(arr[j], size - 3, size);
			j++;
		}
		else if ((size - (i + 1)) % 3 == 1 && str[i] == '1')
		{
			arr[j] = (char *)malloc(sizeof(char) * 3);
			arr[j][0] = str[i];
			arr[j][1] = str[i + 1];
			arr[j][2] = '\0';
			j++;
			if ((size - (i + 2)) % 3 != 0)
				i += 2;
			else
				i += 1;
			continue ;
		}
		else if ((size - (i + 1)) % 3 == 1 && str[i] != '0')
		{
			arr[j] = (char *)malloc(sizeof(char) * 3);
			arr[j][0] = str[i];
			arr[j][1] = '0';
			arr[j][2] = '\0';
			j++;
		}
		else if ((size - (i + 1)) % 3 == 0 && str[i] != '0')
		{
			flag = 0;
			if (i > 0 && str[i - 1] == '1')
				flag = 1;
			if (flag == 0)
			{
				arr[j] = (char *)malloc(sizeof(char) * 2);
				arr[j][0] = str[i];
				arr[j][1] = '\0';
				j++;
			}
		}
		i++;
	}
	arr[j] = 0;
}

char	**read_num(char *str)
{
	char	**arr;
	int		size;
	int		i;

	size = len_num(str);
	arr = (char **)malloc(sizeof(char *) * (size_of_arr(str, size) + 1));
	i = 0;
	malloc_arr(arr, str, size, i);
	return (arr);
}
