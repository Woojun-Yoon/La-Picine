/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:38:48 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/03 16:02:17 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_str(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	write(1, str, len);
}

int	main(int ac, char *av[])
{	
	int	i;

	i = 1;
	while (i < ac)
	{
		print_str(av[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
