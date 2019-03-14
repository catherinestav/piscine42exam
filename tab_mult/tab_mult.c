/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:04:31 by vrestles          #+#    #+#             */
/*   Updated: 2019/03/12 18:12:49 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &(str[i]), 1);
		i++;
	}
}

static void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		n = -1 * n;
		ft_putstr("-");
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

static int	ft_make_integer(char *str)
{
	int n;
	int	i;
	int sign;

	i = 0;
	n = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		str++;
	}
	while (str[i])
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (sign * n);
}

static void	ft_print_tab(char *str)
{
	int n;
	int i;

	n = ft_make_integer(str);
	i = 1;
	while (i <= 9)
	{
		ft_putnbr(i);
		ft_putstr(" x ");
		ft_putnbr(n);
		ft_putstr(" = ");
		ft_putnbr(i * n);
		ft_putstr("\n");
		i++;
	}
}

int			main(int argc, char *argv[])
{
	if (argc == 2)
		ft_print_tab(argv[1]);
	else
		ft_putstr("\n");
	return (0);
}
