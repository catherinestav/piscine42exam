/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 20:15:11 by vrestles          #+#    #+#             */
/*   Updated: 2018/09/12 15:08:03 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str)
{
	int sign;
	int result;

	sign = 1;
	result = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v' || *str == '\r'
			|| *str == '\f' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (sign * result);
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

void	ft_print_hex(int num)
{
	char buff;

	if (num > 16)
		ft_print_hex(num / 16);
	num = num % 16;
	if (num >= 0 && num <= 9)
		buff = num + '0';
	else
		buff = num + 87;
	write(1, &buff, 1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
