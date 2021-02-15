/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:48:46 by spoliart          #+#    #+#             */
/*   Updated: 2021/02/14 23:31:57 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_print_d2(int *fl, int ret, int len)
{
	if (fl[3] && fl[4] && fl[1] < 0)
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

int			ft_print_d(long nb, int *fl)
{
	int ret;
	int len;

	len = ft_nbrlen(nb);
	ret = len;
	if ((fl[4] && (fl[3] || fl[5])) || fl[5])
		ret += ft_putxchar_fd(' ', 1, fl[1] - fl[6] - len);
	if (nb < 0)
		nb = -nb + 0 * write(1, "-", 1);
	if (fl[3] || fl[4])
		ret += ft_putxchar_fd('0', 1, fl[6] - len);
	ft_putnbr_fd((int)nb, 1);
	if (fl[2])
	{
		if (fl[1] < 0)
			fl[1] = -fl[1];
		ret += ft_putxchar_fd(' ', 1, fl[1] - fl[6] - len);
	}
	return (ft_print_d2(fl, ret, len));
}
