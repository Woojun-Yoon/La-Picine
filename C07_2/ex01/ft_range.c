/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:31:17 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/07 14:22:14 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	unsigned long long	size;
	unsigned long long	index;
	int					*nums;

	nums = 0;
	if (min >= max)
		return (nums);
	size = max - min;
	nums = malloc(sizeof(int) * size);
	index = 0;
	while (index < size)
	{
		nums[index] = min;
		min++;
		index++;
	}
	return (nums);
}
