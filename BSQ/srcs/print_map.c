/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:58:36 by woojun            #+#    #+#             */
/*   Updated: 2022/09/14 17:40:11 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "print_map.h"

void	change_map(t_location max, char fill_map, char **map)
{
	int	start_x;
	int	start_y;
	int	temp;

	start_x = max.x - max.square + 1;
	start_y = max.y - max.square + 1;
	temp = start_x;
	while (start_y <= max.y)
	{
		start_x = temp;
		while (start_x <= max.x)
		{
			map[start_y][start_x] = fill_map;
			start_x++;
		}
		start_y++;
	}
}
// max 구조체에는 x, y, 정사각형의 선의 길이가 저장되어있음
// 시작이 되는 x, y 좌표를 구한후, 그 부분부터 찬공간을 나타내는 아스키코드값으로 반복문을 이용해서 채움

int	**find_first_line(t_location map_size, char **map, char empty)
{
	int	i;
	int	**dp;
	int	limit;

	i = -1;
	limit = find_max(map_size.y, map_size.x);
	dp = set_int_map(map_size);
	if (!dp)
		return (0);
	i = -1;
	while (++i < limit)
	{
		if (i < map_size.y && map[i][0] == empty)
			dp[i][0] = 1;
		else if (i < map_size.y && map[i][0] != empty)
			dp[i][0] = 0;
		if (i < map_size.x && map[0][i] == empty)
			dp[0][i] = 1;
		else if (i < map_size.x && map[0][i] != empty)
			dp[0][i] = 0;
	}
	return (dp);
}
// 세로, 가로 길이중 가장 긴값을 limit로 두고, map과 똑같은 2차원 배열을 동적할당하여 dp에 선언후, 맨 윗줄과 맨 왼쪽줄을
// 빈공간이면 1, 아니면 0으로 초기화후 dp를 return

t_location	use_dp(t_location map_size, int **dp, char **map, char disable)
{
	int			i;
	int			j;
	t_location	max;

	i = -1;
	max.square = 0;
	while (++i < map_size.y)
	{
		j = -1;
		while (++j < map_size.x)
		{
			if (map[i][j] == disable)
				dp[i][j] = 0;
			else if (i != 0 && j != 0)
				dp[i][j] = 1 + find_min(dp, i, j);
			if (max.square < dp[i][j])
			{
				max.square = dp[i][j];
				max.x = j;
				max.y = i;
			}
		}
	}
	return (max);
}
// 해당 dp map의 맨 왼쪽 윗 부분부터 search하면서 맨아래 맨 오른쪽으로 이동
// 탐색하면서 장애물이 나오면, 0으로 두고, 장애물이 아니면, 해당칸 기준 왼쪽, 위쪽, 왼쪽위쪽(대각선)
// 3까지 값중 가장 작은값 + 1(정사각형 탐색)
// 그 값이 0으로 초기화 했었던 max.square 보다 크면 그값으로 바꾸고, 해당칸의 x, y좌표를 구조체에 저장
// 가장 큰 정사각형이 될 부분의 x, y, 선의 길이를 return 

int	find_max_square(char **map, int y_size, char *sign)
{
	int			**dp;
	int			i;
	t_location	max;
	t_location	map_size;

	map_size.x = 0;
	map_size.y = y_size;
	max.square = 0;
	while (map[0][map_size.x])
		map_size.x++;
	dp = find_first_line(map_size, map, sign[0]);
	if (!dp)
		return (0);
	max = use_dp(map_size, dp, map, sign[1]);
	change_map(max, sign[2], map);
	i = -1;
	while (++i < map_size.y)
		free(dp[i]);
	free(dp);
	return (1);
}
// 구조체를 선언한 후, 구조체의 x, y에 map의 가로, 세로 최대길이를 저장
// dp를 이용하기 위해서, map의 빈공간은 1, 그외의 공간은 0으로 또다른 map을 dp에 저장 (find_first_line)
// 받아온 dp map을 use_dp 함수로 넘김
// use_dp 함수로 부터 받은 max 구조체를 change_map 함수에 인자로 넘김
// 더이상 쓰지않는 dp map을 동적할당 해제

int	print_map(char **map, int size, char *sign)
{
	int	i;
	int	x_size;

	if (!find_max_square(map, size, sign))
		return (0);
	i = 0;
	x_size = 0;
	while (map[0][x_size])
		x_size++;
	while (i < size)
	{
		write(1, map[i], x_size);
		write(1, "\n", 1);
		i++;
	}
	return (1);
}
// find_max_square로 입력받은 map, 줄의 수, map의 정보가 담긴 sign을 인자로 받아옴
// while 문을 이용해서, find_max_square함수를 통해 결과값이된 map을 출력
