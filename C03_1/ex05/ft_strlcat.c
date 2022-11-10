/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:04:46 by wyoon             #+#    #+#             */
/*   Updated: 2022/08/31 12:12:44 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	d_index;
	unsigned int	s_index;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	d_index = 0;
	s_index = 0;
	while (dest[d_index] != '\0')
	{
		d_index++;
	}
	while (src[s_index] != '\0' && d_index + s_index + 1 < size)
	{
		dest[d_index + s_index] = src[s_index];
		s_index++;
	}
	dest[d_index + s_index] = '\0';
	if (size > d_len)
		return (s_len + d_len);
	else
		return (s_len + size);
}

// 두 문자열을 붙이는 함수이다
// dest의 맨 뒤에 src를 size 만큼만 붙힌다.
// size가 dest의 크기보다 크면 s_len + d_len
// 작거나 같으면 s_len + size('\0') 값 생각