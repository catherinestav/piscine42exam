/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:20:59 by vrestles          #+#    #+#             */
/*   Updated: 2018/09/12 15:10:07 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_denominator(int a, int b)
{
	int rem;

	while (b != 0)
	{
		rem = a % b;
		a = b;
		b = rem;
	}
	return (a);
}

int		main(int argc, char **argv)
{
	int a;
	int b;

	if (argc == 3)
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		printf("%d", ft_denominator(a, b));
	}
	else
		printf("\n");
}
