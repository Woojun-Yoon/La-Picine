/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:26:04 by wyoon             #+#    #+#             */
/*   Updated: 2022/08/27 14:58:09 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	comb_print(char *nums, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		write(1, &nums[i], 1);
		i++;
	}
	write(1, ", ", 2);
}

void	comb(int prev, int n, int index, char *nums)
{
	int		i;

	i = 0;
	if (index == n)
	{
		comb_print(nums, n);
		return ;
	}
	while (prev < 10 - (n - index))
	{
		nums[index] = prev + 1 + '0';
		comb(prev + 1, n, index + 1, nums);
		prev++;
	}
}

void	ft_print_combn(int n)
{
	char	nums[10];
	char	index;
	char	temp;

	index = 0;
	while (index < 10 - n)
	{
		nums[0] = index + '0';
		comb(index, n, 1, nums);
		index++;
	}
	while (index < 10)
	{
		temp = index + '0';
		write(1, &temp, 1);
		index++;
	}
}

int main()
{
	ft_print_combn(4);
	return 0;
}
