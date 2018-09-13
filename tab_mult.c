/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 21:02:29 by vrestles          #+#    #+#             */
/*   Updated: 2018/09/12 15:07:09 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int num)
{
	char c;

	if (num >= 10)
		ft_putnbr(num / 10);
	num = num % 10;
	c = num + '0';
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_atoi(char *str)
{
	int number;

	number = 0;
	while (*str != '\0')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number);
}

void	ft_mult(int num)
{
	int i;

	i = 1;
	while (i <= 9)
	{
		ft_putnbr(i);
		ft_putstr(" x ");
		ft_putnbr(num);
		ft_putstr(" = ");
		ft_putnbr(i * num);
		write(1, "\n", 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_mult(ft_atoi(argv[1]));
	}
	else
		write(1, "\n", 1);
	return (0);
}
