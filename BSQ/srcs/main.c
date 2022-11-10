/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:56:42 by woojun            #+#    #+#             */
/*   Updated: 2022/09/15 13:03:47 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "main.h"

char	*set_first(int size, char *sign, int *sum)
{
	int		i;
	char	*word;

	word = (char *)malloc(sizeof(char) * 4);
	if (!word)
		return (0);
	i = -1;
	while (++i < 4)
	{
		word[i] = sign[size - 4 + i];
		if (same_check(word[i], word, i) || (word[i] < 32 || word[i] > 126))
			if (i != 3)
				return (0);
		sign[size - 4 + i] = 0;
	}
	i = -1;
	*sum = 0;
	while (sign[++i])
	{
		if (sign[i] < '0' || sign[i] > '9')
			return (0);
		*sum = *sum * 10 + (sign[i] - '0');
	}
	free(sign);
	return (word);
}
// map의 정보는 총 4가지 (몇 줄인지, 빈 공간, 장애물 공간, 정사각형 공간)
// (빈 공간, 장애물 공간, 정사각형 공간) -> word
// 해당 정보들에 중복이 없는지, 출력할수 있는 값인지 체크함
// sum <- map의 세로줄의 수(int로 넘김), 필요없는 sign은 free()

char	*input_first(int fd, int *sum)
{
	char	*sign;
	char	*word;
	char	c;
	int		size;

	sign = (char *)malloc(sizeof(char));
	if (!sign)
		return (0);
	size = 1;
	c = 0;
	while (c != '\n')
	{
		if (!read(fd, &c, 1))
			return (0);
		if (c != '\n')
		{
			sign[size - 1] = c;
			add(&size, &sign);
		}
	}
	if (size < 5)
		return (0);
	word = set_first(size, sign, sum);
	return (word);
}
// sign <- map의 정보가 담긴 첫줄을 받아옴, add 함수를 이용해서 한줄을 동적할당 하여 set_first에 넘김
// 넘기면 sum에는 map의 세로줄의 수가, word에는 (빈공간, 장애물, 찬공간) 이 저장되어 return 

void	memory_free(char *sign, char **map)
{
	int	i;

	i = 0;
	free(sign);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}
// 마지막에 동적 할당 했던, map, sign을 free 해줌

int	input_data(int fd)
{
	int			sum;
	char		*sign;
	char		**map;

	sign = input_first(fd, &sum);
	if (!sign || !sum)
		return (0);
	map = make_map(fd, sum, sign);
	if (!map)
		return (0);
	if (!print_map(map, sum, sign))
		return (0);
	memory_free(sign, map);
	return (1);
}
// sign <- ex(10.ox) 와 같은 첫줄을 받아옴(map의 정보를 받아옴)
// map <- input 받은 map을 그대로 동적 할당(map이 잘못되어있으면 error)
// print_map <- map을 기반으로 dp를 이용한, 가장 큰 정사각형을 찾은 후, print
// memory_free <- 동적할당 해제

int	main(int argc, char *argv[])
{
	int	fd;
	int	i;

	fd = 0;
	if (argc < 2)
	{
		if (!input_data(fd))
			write(1, "map error\n", 10);
	}
	else if (argc >= 2)
	{
		i = 0;
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd == -1 || !input_data(fd))
				write(1, "map error\n", 10);
			close(fd);
			if (i != argc - 1)
				write(1, "\n", 1);
		}
	}
	return (0);
}

// 인자가 1개인 경우 -> 표준 입력으로 map을 받아옴 -> 문제가 있으면 error
// 인자가 2개 이상인 경우 -> open 으로 해당 파일을 받아옴 -> 없거나 문제가 있으면 error