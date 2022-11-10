/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:50:31 by wyoon             #+#    #+#             */
/*   Updated: 2022/08/30 15:51:31 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && j < nb)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

// src에 있는 문자열 n개를 문자열 dest 뒤쪽에 이어 붙히는 함수
// dest 문자열의 끝을 가리키는 '\0' 기호 위치에 '\0'를 없애고, src의 문자열 n개를 붙여버림
// dst의 크기 - dst의 len - 1 이 안전한 nb의 최댓값