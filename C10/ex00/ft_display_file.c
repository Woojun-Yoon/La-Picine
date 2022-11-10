/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:27:21 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/14 15:52:27 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	print_str(char *s)
{
	int	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	write(1, s, size);
	write(1, "\n", 1);
}

void	print_file(int check)
{
	char	s;
	int		flag;

	flag = 0;
	while (1)
	{
		flag = read(check, &s, sizeof(char));
		if (!flag)
			break ;
		write(1, &s, 1);
	}
}

int	main(int ac, char **av)
{
	int	check;

	if (ac <= 1)
	{
		print_str("File name missing.");
		return (1);
	}
	else if (ac > 2)
	{
		print_str("Too many arguments.");
		return (1);
	}
	else
	{
		check = open(av[1], O_RDONLY);
		if (check < 0)
		{
			print_str("Cannot read file.");
			return (1);
		}
		else
			print_file(check);
		close(check);
	}
	return (0);
}
