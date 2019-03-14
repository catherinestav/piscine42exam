/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:15:00 by vrestles          #+#    #+#             */
/*   Updated: 2019/03/14 14:00:33 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return ((-1) * n);
	return (n);
}

static void	ft_print_mirror(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 77)
			ft_putchar(str[i] + (ft_abs(str[i] - 77) * 2 + 1));
		else if (str[i] >= 78 && str[i] <= 90)
			ft_putchar(str[i] - (ft_abs(str[i] - 78) * 2 + 1));
		else if (str[i] >= 97 && str[i] <= 109)
			ft_putchar(str[i] + (ft_abs(str[i] - 109) * 2 + 1));
		else if (str[i] >= 110 && str[i] <= 122)
			ft_putchar(str[i] - (ft_abs(str[i] - 110) * 2 + 1));
		else
			ft_putchar(str[i]);
		i++;
	}
}

int			main(int argc, char *argv[])
{
	if (argc == 2)
		ft_print_mirror(argv[1]);
	ft_putchar('\n');
	return (0);
}
