/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 20:04:08 by wyoon             #+#    #+#             */
/*   Updated: 2022/08/28 20:12:11 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len5(char *str)
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

int	ft_str_is_printable(char *str)
{
	int	index;
	int	len;
	int	result;

	len = str_len5(str);
	result = 1;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] < ' ' || str[index] > '~')
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
