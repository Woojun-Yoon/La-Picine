/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:09:02 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/13 20:44:52 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_size(char **tab)
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	*cache;
	int		i;
	int		j;
	int		size;

	i = 0;
	size = get_size(tab);
	while (i < size)
	{
		j = 1;
		while (j < size)
		{
			if (cmp(tab[j - 1], tab[j]) > 0)
			{
				cache = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = cache;
			}
			j++;
		}
		i++;
	}
}
