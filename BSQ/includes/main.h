/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woojun <woojun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:53:26 by woojun            #+#    #+#             */
/*   Updated: 2022/09/13 23:40:08 by woojun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

void	add(int *size, char **s);
char	**make_map(int fd, int sum, char *sign);
int		print_map(char **map, int size, char *sign);
int		same_check(char c, char *sign, int n);

#endif