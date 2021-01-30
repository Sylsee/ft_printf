/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:23:56 by spoliart          #+#    #+#             */
/*   Updated: 2021/01/04 16:23:42 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(long nb)
{
	int count;

	count = 0;
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb > 9)
	{
		nb /= 10;
		count++;
	}
	return (++count);
}

char		*ft_itoa(int n)
{
	int		i;
	long	tmp;
	char	*str;

	tmp = n;
	i = ft_nbrlen(tmp);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (tmp < 0)
	{
		str[0] = '-';
		tmp *= -1;
	}
	i--;
	while (tmp > 9)
	{
		str[i] = tmp % 10 + '0';
		tmp /= 10;
		i--;
	}
	str[i] = tmp % 10 + '0';
	return (str);
}
