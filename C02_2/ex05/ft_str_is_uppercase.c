/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 20:01:57 by wyoon             #+#    #+#             */
/*   Updated: 2022/08/28 20:03:10 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len4(char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		result += 1;
		str += 1;
	}
	return (result);
}

int	ft_str_is_uppercase(char *str)
{
	int	index;
	int	len;
	int	result;

	len = str_len4(str);
	result = 1;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] < 'A' || str[index] > 'Z')
		{
			result = 0;
		}
		index++;
	}
	if (len == 0)
	{
		result = 1;
	}
	return (result);
}
