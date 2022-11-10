/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:51:47 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/11 14:33:15 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int				index;
	unsigned char	s11;
	unsigned char	s22;

	index = 0;
	while (s1[index] != '\0' || s2[index] != '\0')
	{
		if (s1[index] != s2[index])
		{
			s11 = (unsigned char)s1[index];
			s22 = (unsigned char)s2[index];
			return (s11 - s22);
		}	
		index++;
	}
	return (0);
}
