/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 18:16:00 by vrestles          #+#    #+#             */
/*   Updated: 2018/09/11 20:06:01 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	find_str(char *s1, char *s2)
{
	int i;
	int j;
	int	length;
	int	count;

	j = 0;
	length = ft_strlen(s1);
	if (length == 0)
	{
		write(1, "1", 1);
		return ;
	}
	while (s2[j])
	{
		if (s2[j] == s1[0] && *s1 != '\0')
			s1++;
		j++;
	}
	if (ft_strlen(s1) == 0)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		find_str(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
