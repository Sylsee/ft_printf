/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 13:50:47 by spoliart          #+#    #+#             */
/*   Updated: 2021/01/30 17:20:46 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int ft_print_d(int n, int fl[8])
{
	int i;
	int len;
	char *nb;

	i = 0;
	len = ft_nbrlen(n);
	nb = ft_itoa(n);
	if ((fl[2] || ((fl[3] || fl[5]) && fl[4])) && (fl[4] >= (fl[2] || fl[3] || fl[4])))
		if (len < fl[1])
			ft_putxchar_fd(' ', 1, fl[1] - fl[6] - len);
}

int	ft_putxchar_fd(unsigned char c, int fd, int x)
{
	int ret;

	ret = 0;
	while (x--)
		ret += write(fd, &c, 1);
	return (ret);
}
