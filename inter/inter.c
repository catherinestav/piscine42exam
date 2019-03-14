/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:49:04 by vrestles          #+#    #+#             */
/*   Updated: 2019/03/13 14:10:48 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static int	ft_find_letter(char *str, char c, int end)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] && i < end)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_print_found(char *str1, char *str2)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str2);
	while (str1[i])
	{
		if (ft_find_letter(str2, str1[i], len) == 1 &&
			ft_find_letter(str1, str1[i], i) == 0)
			ft_putchar(str1[i]);
		i++;
	}
}

int			main(int argc, char *argv[])
{
	if (argc == 3)
		ft_print_found(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}
