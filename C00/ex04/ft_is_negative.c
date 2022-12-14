/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 05:46:16 by wyoon             #+#    #+#             */
/*   Updated: 2022/08/25 05:55:05 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	cache;

	cache = 'N';
	if (n < 0)
	{
		write(1, &cache, 1);
	}
	else
	{
		cache = 'P';
		write(1, &cache, 1);
	}
}
