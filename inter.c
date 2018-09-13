/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 16:19:33 by vrestles          #+#    #+#             */
/*   Updated: 2018/09/13 17:00:49 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_check(char *str, char c, int k)
{
	int i;

	i = 0;
	while (str[i] && i < k)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_inter(char *s1, char *s2)
{
	int i;
	int length;
	int n;

	i = 0;
	n = 0;
	length = ft_strlen(s2);
	while (s1[i])
	{
		if (ft_check(s2, s1[i], length) == 1)
			if (ft_check(s1, s1[i], n) == 0)
				write(1, &s1[i], 1);
		n++;
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
