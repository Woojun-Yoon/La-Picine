/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:36:32 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/03 16:09:59 by wyoon            ###   ########.fr       */
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
	ac -= 1;
	while (ac > 0)
	{
		print_str(av[ac]);
		write(1, "\n", 1);
		ac--;
	}
	return (0);
}
