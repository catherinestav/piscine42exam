/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:44:28 by vrestles          #+#    #+#             */
/*   Updated: 2018/09/12 15:09:41 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_delimeter(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
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

int		ft_last_symbol(char *str, int length)
{
	length--;
	while (is_delimeter(str[length]) == 1)
		length--;
	return (length);
}

void	ft_epur(char *str, int length)
{
	int i;
	int flag;
	int	last;

	i = 0;
	flag = 0;
	last = ft_last_symbol(str, length);
	while (i <= last)
	{
		if (is_delimeter(str[i]) == 1 && flag == 0)
		{
			write(1, " ", 1);
			flag = 1;
		}
		if (is_delimeter(str[i]) == 0)
		{
			write(1, &str[i], 1);
			flag = 0;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int length;

	if (argc == 2)
	{
		while (is_delimeter(*argv[1]) == 1)
			argv[1]++;
		length = ft_strlen(argv[1]);
		if (length == 0)
		{
			write(1, "\n", 1);
			return (0);
		}
		ft_epur(argv[1], length);
	}
	write(1, "\n", 1);
	return (0);
}
