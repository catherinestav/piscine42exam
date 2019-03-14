/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:25:50 by vrestles          #+#    #+#             */
/*   Updated: 2019/03/13 14:43:22 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	ft_abs(int n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}

int		*ft_range(int start, int end)
{
	int diff;
	int i;
	int	*new;

	diff = ft_abs(start - end) + 1;
	new = (int *)malloc(sizeof(int) * diff);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < diff)
	{
		new[i] = start;
		if (start < end)
			start++;
		else
			start--;	
		i++;
	}
	return (new);
}

void	ft_print_array(int *num, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		printf("%d\n", num[i]);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int *new;
	int start;
	int end;
	
	if (argc == 3)
	{
		start = atoi(argv[1]);
		end = atoi(argv[2]);
		new = ft_range(start, end);
		ft_print_array(new, ft_abs(start - end) + 1);
	}
	return (0);
}
