/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 10:49:13 by vrestles          #+#    #+#             */
/*   Updated: 2018/09/12 15:12:17 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		is_blank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int		is_valid(char c, int base)
{
	char strup[16];
	char strlow[16];

	*strup = "0123456789ABCDEF";
	*strlow = "0123456789abcdef";
	while (base > 0)
	{
		if (c == strup[base - 1] || c == strlow[base - 1])
		{
			return (1);
		}
		base--;
	}
	return (0);
}

int		ft_change_to10(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (is_blank(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (is_valid(*str, str_base))
	{
		result = result * str_base + ft_change_to10(*str);
		str++;
	}
	return (sign * result);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		printf("%d", ft_atoi_base(argv[1], atoi(argv[2])));
	else
		printf("Wrong number of arguments!\n");
	return (0);
}
