/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:57:59 by woojun            #+#    #+#             */
/*   Updated: 2022/09/14 17:25:17 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	add(int *size, char **s)
{
	int		i;
	char	*temp;
	int		new;

	i = 0;
	new = *size + 1;
	temp = (char *)malloc(sizeof(char) * new);
	if (!temp)
		return ;
	while (i < *size)
	{
		temp[i] = (*s)[i];
		i++;
	}
	*size = *size + 1;
	temp[i] = 0;
	free(*s);
	*s = temp;
}
// 동적 할당이 되어있는 s의 size 를 1증가시킨 temp를 리턴하고, s를 동적할당 해제

int	same_check(char c, char *sign, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (sign[i] == c)
			return (1);
		i++;
	}
	return (0);
}
// 해당 sign 문자열에 중복되는 값 c 가 있는지 check, (n 만큼)

char	*read_one(int fd, char *sign)
{
	char	*set;
	char	c;
	int		size;

	set = (char *)malloc(sizeof(char));
	if (!set)
		return (0);
	c = 0;
	size = 1;
	while (c != '\n')
	{
		read(fd, &c, 1);
		if (c != '\n')
		{
			if (!same_check(c, sign, 2))
				return (0);
			set[size - 1] = c;
			add(&size, &set);
		}
	}
	if (size == 1)
		return (0);
	return (set);
}
// 파일디스크립터를 기준으로 엔터가 나올때까지 값을 받아서 set에 저장(한줄 입력받음)
// 엔터만 들어온 경우 error

char	*read_all(int fd, int len, char *sign)
{
	char	*set;
	char	c;
	int		i;

	set = (char *)malloc(sizeof(char) * (len + 1));
	if (!set)
		return (0);
	if (read(fd, set, len) != len)
		return (0);
	set[len] = 0;
	i = -1;
	while (set[++i])
	{
		if (!same_check(set[i], sign, 2))
			return (0);
	}
	read(fd, &c, 1);
	if (c != '\n')
		return (0);
	return (set);
}
// 가로의 길이 만큼이 아닌 줄의 정보는 error 처리
// 정상적이면 엔터가 나올때까지 계속해서 한줄을 입력 받음

char	**make_map(int fd, int sum, char *sign)
{
	char	**map;
	char	c;
	int		i;
	int		len;

	map = (char **)malloc(sizeof(char *) * (sum + 1));
	if (!map)
		return (0);
	i = 0;
	len = 0;
	map[i] = read_one(fd, sign);
	if (!map[i])
		return (0);
	while (map[i][len])
		len++;
	while (++i < sum)
	{
		map[i] = read_all(fd, len, sign);
		if (!map[i])
			return (0);
	}
	if (read(fd, &c, 1) != 0)
		return (0);
	map[i] = 0;
	return (map);
}
// map을 만드는 함수로써 2차원 배열을 동적할당 (sum == 세로줄, 만큼)
// 먼저 한줄을 input 받아온 다음 sign의 세로줄 만큼 그리고, 처음 받은 한줄의 가로줄 만큼 계속 읽는 read_all로 넘김
// len <- 첫줄의 가로의 길이 (다음 줄의 가로길이도 같아야함, 다르면 error)
// 반복문을 돌면서 map의 한줄 한줄을 받아옴
// 모든 줄의 정보를 받아온 후 마지막 값이 EOF면 정상적으로 dp를 이용한 정답 출력으로 넘어감
