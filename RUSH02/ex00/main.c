/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 04:16:03 by jehelee           #+#    #+#             */
/*   Updated: 2022/09/11 20:14:30 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_split.c"
#include "read_num.c"
#include "ft_atoi.c"
#include "dictionary_name.c"
#include "print_dict.c"
#include "check_input.c"

int	ft_strcmp(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*arr1;
	char	*arr2;

	arr1 = (char *)malloc(sizeof(char) * ft_strlen(str1));
	arr2 = (char *)malloc(sizeof(char) * ft_strlen(str2));
	if (!(arr1) || !(arr2))
		return (0);
	i = 0;
	j = 0;
	while (str1[i])
	{
		if (str1[i] >= '0' && str1[i] <= '9')
		{	
			arr1[j] = str1[i];
			j++;
		}
	i++;
	}
	arr1[j] = 0;
	i = 0;
	j = 0;
	while (str2[i])
	{
		if (str2[i] >= '0' && str2[i] <= '9')
		{
			arr2[j] = str2[i];
			j++;
		}
	i++;
	}
	arr2[j] = 0;
	i = 0;
	while (arr1[i] || arr2[i])
	{
		if (arr1[i] != arr2[i])
			return (arr1[i] - arr2[i]);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	int		n;
	char	buf[1000];
	char 	**split;
	char	**sp;
	char	*num = av[1];
	char	**arr_num;
	int		i;
	int		j;
	int		flag;

	if (ac == 2)
	{
		if (!check_input(av[1]))
		{
			ft_putstr("Error\n");
			return (0);
		}
		fd = open("./data/numbers.dict", O_RDWR);
		n = read(fd, buf, 4096);
		split = ft_split(buf, "\n");
		arr_num = read_num(ft_atoi(num));
		if (arr_num == NULL)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		j = 0;
		while (arr_num[j])
		{
			i = 0;
			while (split[i])
			{
				sp = ft_split(split[i], ":");
				if (ft_strcmp(sp[0], arr_num[j]) == 0)
				{
					flag = 1;
					ft_putstr(sp[1]);
				}
				ft_freeall(sp);
				i++;
			}
			if (arr_num[j + 1] != 0)
				ft_putchar(' ');
			j++;
		}
		ft_freeall(split);
		ft_freeall(arr_num);
		if (fd < 0)
			return (-1);
		else
			return (1);
		close(fd);
	}
	if (ac == 3)
	{
		check_input(av[2]);
		fd = open(cat_string("./data/", av[1]), O_RDWR);
		if (fd < 0)
		{
			ft_putstr("Error\n");
			return (-1);
		}
		n = read(fd, buf, 4096);
		split = ft_split(buf, "\n");
		arr_num = read_num(ft_atoi(av[2]));
		j = 0;
		while (arr_num[j])
		{
			i = 0;
			while (split[i])
			{
				sp = ft_split(split[i], ":");
				if (ft_strcmp(sp[0], arr_num[j]) == 0)
					ft_putstr(sp[1]);
				ft_freeall(sp);
				i++;
			}
			if (arr_num[j + 1] != 0)
				ft_putchar(' ');
			j++;
		}
		ft_freeall(split);
		free(arr_num);
		write(1, "\n", 1);
		if (fd < 0)
			return (-1);
		else
			return (1);
		close(fd);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
