/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 18:57:19 by vrestles          #+#    #+#             */
/*   Updated: 2018/09/02 19:44:55 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_rot_13(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'M') ||
			(str[i] >= 'a' && str[i] <= 'm'))
			ft_putchar(str[i] + 13);
		else if ((str[i] >= 'N' && str[i] <= 'Z') ||
			(str[i] >= 'n' && str[i] <= 'z'))
			ft_putchar(str[i] - 13);
		else
			ft_putchar(str[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_rot_13(argv[1]);
	write(1, "\n", 1);
}
