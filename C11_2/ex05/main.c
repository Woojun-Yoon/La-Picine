/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:38:42 by wyoon             #+#    #+#             */
/*   Updated: 2022/09/12 21:31:24 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		plus(int a, int b);
int		minus(int a, int b);
int		multi(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);
int		ft_atoi(char *str);
void	print_result(int n1, int n2, char op, int (*op_arr[5])(int, int));

void	change_form(char *s1, char op, char *s2, int (*op_arr[5])(int, int))
{
	int	n1;
	int	n2;

	n1 = ft_atoi(s1);
	n2 = ft_atoi(s2);
	if (n2 == 0)
	{
		if (op == '/')
		{
			write(1, "Stop : division by zero", 23);
			return ;
		}
		else if (op == '%')
		{
			write(1, "Stop : modulo by zero", 21);
			return ;
		}
	}
	print_result(n1, n2, op, op_arr);
}

int	op_check(char op)
{
	if (op == '+' || op == '-' || op == '/' || op == '%' || op == '*')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	char	*op_input;
	char	op;
	int		(*op_arr[5])(int, int);

	op_arr[0] = plus;
	op_arr[1] = minus;
	op_arr[2] = multi;
	op_arr[3] = div;
	op_arr[4] = mod;
	if (ac == 4)
	{
		op_input = av[2];
		if (op_input[1] == '\0' && op_check(op_input[0]))
		{
			op = op_input[0];
			change_form(av[1], op, av[3], op_arr);
			write(1, "\n", 1);
		}
		else
		{
			write(1, "0\n", 2);
			return (0);
		}
	}
	return (0);
}
