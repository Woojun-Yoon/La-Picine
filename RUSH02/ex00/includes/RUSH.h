/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RUSH.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:29:36 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/11 20:34:09 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

int		check_input(char *str);
char	**ft_freeall(char **list);
int		ft_strlen(char *str);
char	*cat_string(char *str1, char *str2);
int		count_digits(char *str);
char	*ft_itoa(long long n);
int		is_space(char c);
char	*ft_atoi(char *str);
int		check_separator(char c, char *charset);
int		count_strings(char *str, char *charset);
int		ft_strlen_sep(char *str, char *charset);
char	*ft_word(char *str, char *charset);
char	**ft_split(char *str, char *charset);
int		ft_strcmp(char *str1, char *str2);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		len_num(char *str);
void	fill_arr(char *dest, int i, int size);
int		size_of_arr(char *str, int size);
void	malloc_arr(char **arr, char *str, int size, int i);
char	**read_num(char *str);

#endif