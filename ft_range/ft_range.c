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

static int	ft_abs(int n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}

int			*ft_range(int start, int end)
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
