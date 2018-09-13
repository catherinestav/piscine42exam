/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:01:42 by vrestles          #+#    #+#             */
/*   Updated: 2018/09/12 15:21:01 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_num(int num)
{
	char c;

	if (num >= 10)
	{
		ft_print_num(num / 10);
		ft_print_num(num % 10);
	}
	else
	{
		c = num + '0';
		write(1, &c, 1);
	}
}

int		ft_atoi(char *str)
{
	int result;
	int sign;

	sign = 1;
	result = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

int		ft_is_prime(int num)
{
	int i;

	i = 2;
	if (num <= 1)
		return (0);
	while (i < num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_add_prime_numbers(int num)
{
	int i;
	int result;

	i = 1;
	result = 0;
	while (i <= num)
	{
		if (ft_is_prime(i) == 1)
			result = result + i;
		i++;
	}
	ft_print_num(result);
}

int		main(int argc, char **argv)
{
	if (argc == 2 && ft_atoi(argv[1]) > 0)
		ft_add_prime_numbers(ft_atoi(argv[1]));
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
