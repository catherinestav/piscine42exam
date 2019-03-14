/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:17:51 by vrestles          #+#    #+#             */
/*   Updated: 2019/03/14 14:20:55 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	ft_count_digits(int nbr)
{
	int ret;
	
	ret = 1;
	if (nbr == -2147483648)
		return (10);
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		ret++;
	}
	return (ret);
}

static char	*ft_make_string(int nbr, int count, int sign, int tag)
{
	char	*res;
	int		i;
	
	if ((res = (char *)malloc(sizeof(char) * count + 1)) == NULL)
		return (NULL);
	i = count;
	res[i] = '\0';
	i--;
	if (tag == 1)
	{
		res[i] = '8';
		nbr = 214748364;
		i--;
	}
	while (i > 0)
	{
		res[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i--;
	}
	if (sign == 1)
		res[i] = '-';
	else
		res[i] = nbr % 10 + '0';
	return (res);
}

char		*ft_itoa(int nbr)
{
	int		len;
	int		sign;
	char	*res;
	int		tag;
	
	res = NULL;
	sign = 0;
	tag = 0;
	if (nbr < 0)
	{
		sign = 1;
		if (nbr == -2147483648)
			tag = 1;
		else
			nbr = -1 * nbr;
	}
	len = ft_count_digits(nbr);
	res = ft_make_string(nbr, len + sign, sign, tag);
	return (res);
}

int			main(int argc, char *argv[])
{
	char	*res;

	res = NULL;
	if (argc == 2)
	{
		res = ft_itoa(atoi(argv[1]));
		printf("result: %s|\n", res);
	}
	return (0);
}
