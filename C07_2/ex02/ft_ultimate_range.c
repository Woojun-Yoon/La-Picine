/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 19:07:37 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/07 14:29:55 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned long long	size;
	unsigned long long	index;

	*range = 0;
	if (min >= max)
		return (0);
	size = max - min;
	*range = malloc(sizeof(int) * size);
	if (*range == 0)
		return (-1);
	index = 0;
	while (index < size)
	{
		(*range)[index] = min;
		min++;
		index++;
	}
	return (size);
}
