/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:28:16 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/04 23:12:41 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_nums(int *nums)
{
	int		index;
	char	cache;

	index = 0;
	while (index < 10)
	{
		cache = nums[index] + '0';
		write(1, &cache, 1);
		index++;
	}
	write(1, "\n", 1);
}

int	abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	check(int *nums, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (nums[i] == nums[j])
			return (0);
		if (abs(i - j) == abs(nums[i] - nums[j]))
			return (0);
		j++;
	}
	return (1);
}

void	recur_queen(int *queens, int i, int cur, int *result)
{
	if (i == 10)
	{
		print_nums(queens);
		(*result)++;
		return ;
	}
	while (cur < 10)
	{
		queens[i] = cur;
		if (check(queens, i))
			recur_queen(queens, i + 1, 0, result);
		cur++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	result;
	int	queens[10];

	result = 0;
	recur_queen(queens, 0, 0, &result);
	return (result);
}
