/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:20:27 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/12 21:34:04 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_increase(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	result;

	i = 0;
	while (i < length - 1)
	{
		result = f(tab[i], tab[i + 1]);
		if (result > 0)
			return (0);
		i++;
	}
	return (1);
}
// 음수, 0 일때 오름차순으로 정렬되어 있음

int	ft_decrease(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	result;

	i = 0;
	while (i < length - 1)
	{
		result = f(tab[i], tab[i + 1]);
		if (result < 0)
			return (0);
		i++;
	}
	return (1);
}
// 양수, 0 일때 내림차순으로 정렬되어 있음

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (ft_decrease(tab, length, f) || ft_increase(tab, length, f))
		return (1);
	return (0);
}
