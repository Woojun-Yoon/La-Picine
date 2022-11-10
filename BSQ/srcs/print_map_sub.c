/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:30:18 by woojun            #+#    #+#             */
/*   Updated: 2022/09/14 17:41:16 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"

int	find_min(int **dp, int i, int j)
{
	int	a;
	int	b;
	int	c;
	int	n;

	a = dp[i][j - 1];
	b = dp[i - 1][j];
	c = dp[i - 1][j - 1];
	n = a;
	if (n > b)
		n = b;
	if (n > c)
		n = c;
	return (n);
}
// 해당 칸 (i, j)를 기준으로 왼쪽, 위, 왼쪽위 3가지 값중 가장 작은 값을 return

int	find_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
// 둘중 작은 값을 return 

int	**set_int_map(t_location map_size)
{
	int	**set;
	int	i;

	set = (int **)malloc(sizeof(int *) * map_size.y);
	if (!set)
		return (0);
	i = -1;
	while (++i < map_size.y)
	{
		set[i] = (int *)malloc(sizeof(int) * map_size.x);
		if (!set)
			return (0);
	}
	return (set);
}
// 받아온 구조체의 x, y 값을 이용하여 똑같은 크기의 map을 동적할당 한후 return
