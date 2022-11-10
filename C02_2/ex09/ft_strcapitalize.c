/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:37:16 by wyoon             #+#    #+#             */
/*   Updated: 2022/08/29 16:31:26 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	upper(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
	}
	return (c);
}

char	lower(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 32;
	}
	return (c);
}

int	check_num(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (0);
	}
	else if ((c >= '0' && c <= '9'))
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

char	*ft_strcapitalize(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (index == 0 || check_num(str[index - 1]))
		{
			str[index] = upper(str[index]);
		}
		else
		{
			str[index] = lower(str[index]);
		}
		index++;
	}
	return (str);
}
