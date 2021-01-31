/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 13:50:47 by spoliart          #+#    #+#             */
/*   Updated: 2021/01/31 16:02:51 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int ft_print_d(long nb, int fl[8])
{
	int ret;
	int len;

	len = ft_nbrlen(nb);
	ret = len;
	if ((fl[4] && (fl[3] || fl[5])) || fl[5])
		ret += ft_putxchar_fd(' ', 1, fl[1] - fl[6] - len);
	if (n < 0)
		nb = -nb + 0 * write(1, '-', 1);
	if (fl[3] || fl[4])
		ret += ft_putxchar_fd('0', 1, fl[6] - len);
	ft_putnbr_fd((int)nb, 1);
	if (fl[2])
	{
		if (fl[1] < 0)
			fl[1] = -fl[1];
		ret += ft_putxchar_fd(' ', 1, fl[1] - fl[6] - len);
	}
	else if (fl[3] && fl[4] && fl[1] < 0)
	{
		fl[1] = -fl[1];
		ret += ft_putxchar_fd(' ', 1, fl[1] - fl[6] - len);
	}
	else if (fl[3] && fl[6] < 0)
	{
		fl[6] = -fl[6];
		ret += ft_putxchar_fd(' ', 1, fl[1] - fl[6] - len);
	}
	return (ret);
}

int	ft_print_c(char c, int fl[8])
{
	int ret;

	ret = 1;
	if (fl[5])
		ret += ft_putxchar_fd(' ', 1, fl[1] - len);
	if (fl[])
	ft_putchar_fd(c, 1);
	if (fl[2])
	{
		if (fl[1] < 0)
			fl[1] = -fl[1];
		ft_putxchar_fd(' ', 1, fl[1] - len);
	}
	else if (fl[5] && fl[1] < 0)
	{
		fl[1] = -fl[1];
		ft_putxchar_fd(' ', 1, fl[1] - len);
	}
	return (ret);
}

char	*ft_cut(char *s, int n)
{
	int i;
	char *ret;

	i = -1;
	ret = (char *)malloc(sizeof(char) * i + 1);
	if (!ret)
		return (NULL);
	while (s[++i] && n--)
		ret[i] = s[i];
	ret[i] = 0;
	return (ret);
}

int ft_print_s(char *s, int fl[8])
{
	int ret;
	int len;

	if (fl[4] && fl[6] >= 0)
		s = ft_cut(s, fl[6]);
	len = ft_strlen(s);
	ret = len;
	if (fl[5])
		ret += ft_putxchar_fd(' ', 1, fl[1] - len);
	free(s);
}


















































