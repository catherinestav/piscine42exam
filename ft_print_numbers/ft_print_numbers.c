/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:38:49 by vrestles          #+#    #+#             */
/*   Updated: 2019/03/13 13:42:52 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_print_numbers(void)
{
	int n;

	n = 48;
	while (n <= 57)
	{
		write(1, &n, 1);
		n++;
	}
}
