/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 15:45:01 by vrestles          #+#    #+#             */
/*   Updated: 2018/09/12 17:30:58 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		is_prime(int num)
{
	int i;

	if (num <= 1)
		return (0);
	i = 2;
	while (i < num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_fprime(int num)
{
	int i;

	i = 2;
	while (i <= num)
	{
		if (is_prime(i) && (num % i == 0))
		{
			printf("%d", i);
			if (num != i)
				printf("*");
			num = num / i;
		}
		else
			i++;
	}
}

int		main(int argc, char **argv)
{
	int num;

	if (argc == 2)
	{
		num = atoi(argv[1]);
		if (is_prime(num))
			printf("%d\n", num);
		else
			ft_fprime(num);
	}
	else
		printf("\n");
	return (0);
}
