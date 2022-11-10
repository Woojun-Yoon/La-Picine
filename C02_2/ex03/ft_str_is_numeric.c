/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:33:56 by wyoon             #+#    #+#             */
/*   Updated: 2022/08/28 19:44:51 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len2(char *str)
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

int	ft_str_is_numeric(char *str)
{
	int	index;
	int	len;
	int	result;

	len = str_len2(str);
	result = 1;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] < '0' || str[index] > '9')
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
