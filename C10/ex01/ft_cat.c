/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:01:11 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/14 17:05:20 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>

void	ft_printstr(char *s)
{	
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	write(1, s, i);
}

void	print_error(char *file, char *p)
{
	ft_printstr(basename(p));
	ft_printstr(": ");
	ft_printstr(file);
	ft_printstr(": ");
	ft_printstr(strerror(errno));
	ft_printstr("\n");
	errno = 0;
}

void	print_file(int fd, char *file, char *p)
{
	long			size;
	unsigned char	c;

	size = read(fd, &c, 1);
	while (size)
	{
		if (errno)
		{
			print_error(file, p);
			return ;
		}
		write(1, &c, size);
		size = read(fd, &c, 1);
	}
}

int	main(int ac, char **av)
{
	int		fd;
	int		i;
	char	*p;

	p = av[0];
	if (ac == 1)
		print_file(0, 0, p);
	else
	{
		i = 0;
		while (++i < ac)
		{
			fd = open(av[i], O_RDONLY);
			if (fd == -1)
			{
				print_error(av[i], p);
				continue ;
			}
			print_file(fd, av[i], p);
			close(fd);
		}
	}
	return (0);
}
