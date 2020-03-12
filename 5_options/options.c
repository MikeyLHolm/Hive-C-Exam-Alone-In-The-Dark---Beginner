/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:01:18 by exam              #+#    #+#             */
/*   Updated: 2020/03/10 14:12:16 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int ac, char **av)
{
	int		i = 0;
	int		j;
	char	arr[] = "00000000000000000000000000000000";
	
	if (ac < 2)
	{
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
		return (0);
	}
	while (++i < ac)
	{
		if (av[i][0] == '-')
		{
			j = 1;
			while (av[i][j])
			{
				if (av[i][j] < 'a' || av[i][j] > 'z')
				{
					write(1, "Invalid Option\n", 15);
					return (0);
				}
				if (av[i][j] == 'h')
				{
					write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
					return (0);
				}
				arr['z' - av[i][j] + 6] = '1';
				j++;
			}
		}
	}
	i = 0;
	while (i < 32)
	{
		if (i == 8 || i == 16 || i == 24)
			write(1, " ", 1);
		write(1, &arr[i++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
