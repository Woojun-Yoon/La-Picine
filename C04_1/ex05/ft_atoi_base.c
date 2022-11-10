/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:20:57 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/01 18:05:25 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
// String 길이 구하는 함수

int	check_space(char str)
{
	if (str == ' ' || str == '\t' || str == '\r'\
	|| str == '\n' || str == '\v' || str == '\f')
		return (1);
	else
		return (0);
}
// 공백을 검사하는 함수

int	base_check(char *base, int len)
{
	int	i;
	int	j;

	i = 0;
	if (len == 0 || len == 1)
		return (1);
	while (base[i] != '\0')
	{	
		if (check_space(base[i]) || base[i] == '-' || base[i] == '+')
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
// 해당 base에 문제가 없는지 확인하는 함수, 문제가 있으면 1을 return

int	find_base(char *base, char c)
{
	int	i;

	i = 0;
	while (i < get_len(base))
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

// base에 해당하는 수를 리턴, 아닌값은 -1을 리턴

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	result;
	int	minus;

	i = 0;
	result = 0;
	minus = 1;
	if (base_check(base, get_len(base)))
		return (0);
	while (check_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (find_base(base, str[i]) != -1)
	{
		result = result * get_len(base) + find_base(base, str[i]);
		i++;
	}
	return (result * minus);
}
