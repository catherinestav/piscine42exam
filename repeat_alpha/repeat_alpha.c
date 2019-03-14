/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:07:02 by vrestles          #+#    #+#             */
/*   Updated: 2019/03/12 15:16:13 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void		ft_putchar(char c)
{
	write(1, &c, 1);
}

static int		ft_get_index(char c)
{
	int i;
	int small;
	int big;

	i = 1;
	small = 97;
	big = 65;
	while (i <= 26)
	{
		if (c == small || c == big)
			break ;
		i++;
		small++;
		big++;
	}
	return (i);
}

static void		ft_print_letter(char c)
{
	int i;
	int count;

	count = ft_get_index(c);
	i = 0;
	while (i < count)
	{
		ft_putchar(c);
		i++;
	}
}

int				main(int argc, char *argv[])
{
	int i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if ((argv[1][i] >= 97 && argv[1][i] <= 122) ||
					(argv[1][i] >= 65 && argv[1][i] <= 90))
				ft_print_letter(argv[1][i]);
			else
				ft_putchar(argv[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
