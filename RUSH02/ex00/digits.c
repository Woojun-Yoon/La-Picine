/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:44:50 by jehelee           #+#    #+#             */
/*   Updated: 2022/09/11 20:17:56 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_digits(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] && str[i] != ' ')
	{
		i++;
		if (i % 3 == 0)
			count += 1;
	}
	return (count);
}

char	*ft_itoa(long long n)
{
	int			i;
	long long	temp;
	int			count;
	char		*str;

	temp = n;
	while (n > 0)
	{
		temp /= 10;
		count++;
	}
	str = (int *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (0);
	str[0] = '1';
	i = 1;
	while (i < count)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
