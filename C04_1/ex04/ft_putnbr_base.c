/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:27:19 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/01 17:45:40 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_len1(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
// String 길이 구하는 함수

int	base_check1(char *base, int len)
{
	int	i;
	int	j;

	i = 0;
	if (len == 0 || len == 1)
		return (1);
	while (base[i] != '\0')
	{	
		if (base[i] == '+' || base[i] == '-')
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

void	print_base_num(long long nbr, char *base, int base_len)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr != 0)
	{
		print_base_num(nbr / base_len, base, base_len);
		write(1, &base[nbr % base_len], 1);
	}
}
// 제귀를 이용하여 한자리 씩 base에 해당하는 자릿수를 출력

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = get_len1(base);
	nbr = (long long)nbr;
	if (base_check1(base, base_len))
		return ;
	if (nbr == 0)
		write(1, &base[0], 1);
	else
		print_base_num(nbr, base, base_len);
}
// 메인이 되는 함수로써 변수를 받아와서 각 함수에 input해줌
