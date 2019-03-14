/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_revalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:38:04 by vrestles          #+#    #+#             */
/*   Updated: 2019/03/12 14:54:07 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int			main(void)
{
	int i;
	int	small_letter;
	int	big_letter;

	i = 1;
	small_letter = 122;
	big_letter = 90;
	while (i <= 26)
	{
		if (i % 2 == 0)
			write(1, &big_letter, 1);
		else
			write(1, &small_letter, 1);
		small_letter--;
		big_letter--;
		i++;
	}
	ft_putchar('\n');
	return (0);
}
