/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:38:22 by wyoon             #+#    #+#             */
/*   Updated: 2022/08/28 19:29:43 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str)
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

int	ft_str_is_alpha(char *str)
{
	int	index;
	int	result;
	int	len;

	len = str_len(str);
	index = 0;
	result = 1;
	while (str[index] != '\0')
	{
		if (str[index] < 'a' && str[index] > 'Z')
		{
			result = 0;
		}
		else if (str[index] < 'A' || str[index] > 'z')
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
