/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:13:42 by exam              #+#    #+#             */
/*   Updated: 2019/12/03 14:46:11 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	rev_wstr(char *str)
{
	int		i;
	int		j;

	if (!str)
		return ;
	i = 0;
	while (str[i] != '\0')
		i++;
	while (i > 0)
	{
		while (str[i] == '\0' || str[i] == ' ' || str[i] == '\t')
			i--;
		j = i;
		while (j > 0 && (str[j] != '\t' && str[j] != ' '))
			j--;
		if (j != 0)
		{
			write(1, str + j + 1, i - j);
			write(1, " ", 1);
		}
		else
			write(1, str, i + 1);
		i = j;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
