/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:01:40 by exam              #+#    #+#             */
/*   Updated: 2020/02/25 14:34:56 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_pal(char *str, int low, int high)
{
	while (low <= high)
		write(1, &str[low++], 1);
}

void	biggest_pal(char *str)
{
	int		i = 0;
	int		len = 0;
	int		max = 1;
	int		low, high, start;

	while (str[len])
		len++;
	while (++i < len)
	{
		low = i - 1;
		high = i;
		while (low >= 0 && high < len && str[low] == str[high])
		{
			if (high - low + 1 >= max)
			{
				start = low;
				max = high - low + 1;
			}
			--low;
			++high;
		}
		low = i - 1;
		high = i + 1;
		while (low >= 0 && high < len && str[low] == str[high])
		{
			if (high - low + 1 >= max)
			{
				start = low;
				max = high - low + 1;
			}
			--low;
			++high;
		}
	}
	if (max == 1)
		start = i - 1;
	print_pal(str, start, start + max - 1);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		biggest_pal(av[1]);
	write(1, "\n", 1);
	return (0);
}
