/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 13:50:47 by spoliart          #+#    #+#             */
/*   Updated: 2021/01/31 14:10:07 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int ft_print_d(int n, int fl[8])
{
	int ret;
	int len;
	long nb;

	nb = n;
	len = ft_nbrlen(n);
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
	if (fl[3] && fl[4] && fl[1] < 0)
	{
		fl[1] = -fl[1];
		ret += ft_putxchar_fd(' ', 1, fl[1] - fl[6] - len);
	}
}
