/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:42:33 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/01 18:05:23 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	index;
	int	check;
	int	result;

	index = 0;
	check = 1;
	result = 0;
	while (str[index] == ' ' || str[index] == '\t' || str[index] == '\r'\
	|| str[index] == '\n' || str[index] == '\v' || str[index] == '\f')
	{
		index++;
	}
	while (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			check *= -1;
		index++;
	}
	while ('0' <= str[index] && str[index] <= '9')
	{
		result = result * 10 + (str[index] - '0');
		index++;
	}
	return (check * result);
}
