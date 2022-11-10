/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woojun <woojun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 07:54:19 by woojun            #+#    #+#             */
/*   Updated: 2022/09/13 23:40:09 by woojun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_MAP_H
# define PRINT_MAP_H

# include "struct.h"

int	find_min(int **dp, int i, int j);
int	find_max(int a, int b);
int	**set_int_map(t_location map_size);

#endif