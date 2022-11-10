/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:53:30 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/03 21:03:21 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] || s2[index])
	{
		if (s1[index] > s2[index])
			return (1);
		else if (s1[index] < s2[index])
			return (-1);
		index++;
	}
	return (0);
}

void	print_str(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	write(1, str, len);
}

void	sort_ascii(int ac, char *av[])
{
	char	*cache;
	int		i;
	int		j;

	i = 0;
	while (i < ac)
	{
		j = 1;
		while (j < ac - 1)
		{
			if (ft_strcmp(av[j], av[j + 1]) == 1)
			{
				cache = av[j];
				av[j] = av[j + 1];
				av[j + 1] = cache;
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char *av[])
{
	int	i;

	sort_ascii(ac, av);
	i = 1;
	while (i < ac)
	{
		print_str(av[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
