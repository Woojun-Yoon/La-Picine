/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:45:51 by wyoon             #+#    #+#             */
/*   Updated: 2022/08/28 20:00:54 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len3(char *str)
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

int	ft_str_is_lowercase(char *str)
{
	int	index;
	int	len;
	int	result;

	len = str_len3(str);
	result = 1;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] < 'a' || str[index] > 'z')
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
