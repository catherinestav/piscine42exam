/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:13:21 by vrestles          #+#    #+#             */
/*   Updated: 2018/09/13 16:18:36 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		is_blank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	ft_rev(char *str)
{
	int i;
	int count;

	count = 0;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (is_blank(str[i]) == 1)
		{
			str[i] = '\0';
			write(1, &(str[i]) + 1, count);
			write(1, " ", 1);
			count = 0;
		}
		else
			count++;
		i--;
	}
	write(1, &str[i + 1], count);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_rev(argv[1]);
	}
	else
		write(1, "\n", 1);
	return (0);
}
