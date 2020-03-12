/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:01:37 by exam              #+#    #+#             */
/*   Updated: 2019/12/10 14:46:23 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_intlen(int nb)
{
	int		len;

	len = 0;
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len + 1);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i = 0;

	if (!(s2 = (char *)malloc(sizeof(char) * 12)))
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		len;
	int		sign;

	sign = 1;
	if (nbr == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	if (nbr < 0)
	{
		nbr *= -1;
		sign = -1;
	}
	len = ft_intlen(nbr);
	if (sign == -1)
		len += 1;
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (sign == -1)
		str[0] = '-';
	str[len] = '\0';
	len--;
	while (len >= 0 && nbr >= 10)
	{
		str[len] = nbr % 10 + 48;
		nbr /= 10;
		len--;
	}
	str[len] = nbr + 48;
	return (str);
}
