/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:48:46 by spoliart          #+#    #+#             */
/*   Updated: 2021/02/20 01:44:29 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_print_d2(int *fl, int ret, int len)
{
	if (fl[2])
	{
		if (fl[1] < 0)
			fl[1] = -fl[1];
		ft_ternary(fl, &ret, len);
	}
	if (fl[3] && fl[4] && fl[1] < 0)
	{
		fl[1] = -fl[1];
		ft_ternary(fl, &ret, len);
	}
	else if (fl[3] && fl[6] < 0)
	{
		fl[6] = -fl[6];
		ft_ternary(fl, &ret, len);
	}
	return (ret);
}

int			ft_print_d(long nb, int *fl)
{
	int ret;
	int len;

	len = ft_nbrlen(nb);
	if (fl[4] && !fl[6] && !nb && ++fl[7])
		len = 0;
	ret = len;
	if (fl[5] || (fl[3] && fl[4]))
		ft_ternary(fl, &ret, len);
	if (nb < 0)
		nb = -nb + 0 * write(1, "-", 1);
	if (fl[3] && !fl[4])
		ret += ft_putxchar_fd('0', 1, fl[1] - len);
	else if (fl[4])
		ret += ft_putxchar_fd('0', 1, fl[6] - len + fl[8]);
	if (!fl[7])
		ft_putnbr_fd((int)nb, 1);
	return (ft_print_d2(fl, ret, len));
}
//	0 prends en compte '-'
//	. prends pas en compte '-'





