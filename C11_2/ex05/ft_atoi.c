/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:32:14 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/12 17:36:12 by wyoon            ###   ########.fr       */
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
	while (str[index] == ' ')
		index++;
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
