/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:00:17 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/12 21:31:33 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_num(int num)
{
	long long	cache;
	char		s;

	if (num < 0)
	{
		write(1, "-", 1);
		cache = ((long long)num) * -1;
	}
	else
		cache = (long long)num;
	if (cache >= 10)
		ft_print_num(cache / 10);
	s = cache % 10 + '0';
	write(1, &s, 1);
}

void	print_result(int n1, int n2, char op, int (*op_arr[5])(int, int))
{
	int	result;

	result = 0;
	if (op == '+')
		result = op_arr[0](n1, n2);
	else if (op == '-')
		result = op_arr[1](n1, n2);
	else if (op == '*')
		result = op_arr[2](n1, n2);
	else if (op == '/')
		result = op_arr[3](n1, n2);
	else if (op == '%')
		result = op_arr[4](n1, n2);
	ft_print_num(result);
}
