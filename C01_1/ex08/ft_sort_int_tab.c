/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:47:40 by wyoon             #+#    #+#             */
/*   Updated: 2022/08/28 15:02:00 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	cache;

	i = 0;
	while (i < size)
	{	
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				cache = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = cache;
			}
			j++;
		}
		i++;
	}
}
