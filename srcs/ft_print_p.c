/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:53:06 by spoliart          #+#    #+#             */
/*   Updated: 2021/02/22 19:02:25 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_print_p3(int *fl, int ret, int len)
{
	if (fl[2])
	{
		if (fl[1] < 0)
			fl[1] = -fl[1];
		ret += ft_putxchar_fd(' ', 1, fl[1] - len - 2);
	}
	else if ((fl[3] || fl[5]) && fl[1] < 0)
	{
		fl[1] = -fl[1];
		ret += ft_putxchar_fd(' ', 1, fl[1] - len - 2);
	}
	return (ret);
}

static int	ft_print_p2(char *s, int *fl)
{
	int	ret;
	int	len;

	len = ft_strlen(s);
	ret = len + 2;
	if (fl[5] || (fl[3] && fl[4]))
		ret += ft_putxchar_fd(' ', 1, fl[1] - len - 2);
	ft_putstr_fd("0x", 1);
	if (fl[3] && !fl[4])
		ret += ft_putxchar_fd('0', 1, fl[1] - len - 2);
	else if (fl[4])
		ret += ft_putxchar_fd('0', 1, fl[6] - len);
	ft_putstr_fd(s, 1);
	free(s);
	return (ft_print_p3(fl, ret, len));
}

int			ft_print_p(unsigned long n, int *fl)
{
	int				len;
	char			*s;
	unsigned long	nb;

	nb = n;
	len = 0;
	while (nb)
		nb /= 16 + 0 * len++;
	s = (char *)malloc(sizeof(s) * (len + 1));
	if (!s)
		return (-1);
	nb = n;
	if (!len && ((fl[4] && fl[6]) || !fl[4]))
		s[len++] = '0';
	s[len] = '\0';
	while (len--)
	{
		if (nb % 16 < 10)
			s[len] = (nb % 16) + 48;
		else
			s[len] = (nb % 16) + 87;
		nb /= 16;
	}
	return (ft_print_p2(s, fl));
}
