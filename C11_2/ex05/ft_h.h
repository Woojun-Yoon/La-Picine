/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:44:21 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/12 21:31:11 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H

int		ft_atoi(char *str);

int		plus(int a, int b);
int		minus(int a, int b);
int		multi(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);

void	ft_print_num(int num);
void	print_result(int n1, int n2, char op);

#endif