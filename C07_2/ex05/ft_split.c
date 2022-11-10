/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:09:11 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/07 17:05:50 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_sep(char c, char *sep)
{	
	int	i;

	i = 0;
	if (c == 0)
		return (1);
	while (sep[i] != '\0')
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_str(char *str, char *sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && check_sep(str[i], sep))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !check_sep(str[i], sep))
			i++;
	}
	return (count);
}

int	strlen_sep(char *str, char *sep)
{
	int	i;

	i = 0;
	while (str[i] && !check_sep(str[i], sep))
		i++;
	return (i);
}

char	*ft_word(char *str, char *sep)
{
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	len_word = strlen_sep(str, sep);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;

	i = 0;
	result = (char **)malloc(sizeof(char *)
			* (count_str(str, charset) + 1));
	while (*str != '\0')
	{
		while (*str != '\0' && check_sep(*str, charset))
			str++;
		if (*str != '\0')
		{
			result[i] = ft_word(str, charset);
			i++;
		}
		while (*str && !check_sep(*str, charset))
			str++;
	}
	result[i] = 0;
	return (result);
}
