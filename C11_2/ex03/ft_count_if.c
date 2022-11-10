/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:18:16 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/11 21:55:15 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			result += 1;
		i++;
	}
	return (result);
}
