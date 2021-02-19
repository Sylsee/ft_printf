/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:51:36 by spoliart          #+#    #+#             */
/*   Updated: 2021/02/19 18:32:30 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_print_c(char c, int *fl)
{
	int	ret;

	ret = 1;
	if (fl[5])
		ret += ft_putxchar_fd(' ', 1, fl[1] - 1);
	if (fl[3])
		ret += ft_putxchar_fd('0', 1, fl[1] - 1);
	ft_putchar_fd(c, 1);
	if (fl[2])
	{
		if (fl[1] < 0)
			fl[1] = -fl[1];
		ret += ft_putxchar_fd(' ', 1, fl[1] - 1);
	}
	else if ((fl[3] || fl[5]) && fl[1] < 0)
	{
		fl[1] = -fl[1];
		ret += ft_putxchar_fd(' ', 1, fl[1] - 1);
	}
	return (ret);
}

static int	ft_print_s2(char *s, int *fl, int ret, int len)
{
	if (fl[2])
	{
		if (fl[1] < 0)
			fl[1] = -fl[1];
		ret += ft_putxchar_fd(' ', 1, fl[1] - len);
	}
	else if ((fl[3] || fl[5]) && fl[1] < 0)
	{
		fl[1] = -fl[1];
		ret += ft_putxchar_fd(' ', 1, fl[1] - len);
	}
	if (fl[7])
		free(s);
	return (ret);
}

int			ft_print_s(char *s, int *fl)
{
	int	ret;
	int	len;

	if (!s)
		s = ft_strdup("(null)") + 0 * ++fl[7];
	if (fl[4] && fl[6] >= 0)
		s = ft_cut(s, fl[6]) + 0 * ++fl[7];
	if (!s)
		return (-1);
	len = ft_strlen(s);
	ret = len;
	if (fl[5])
		ret += ft_putxchar_fd(' ', 1, fl[1] - len);
	if (fl[3])
		ret += ft_putxchar_fd('0', 1, fl[1] - len);
	ft_putstr_fd(s, 1);
	ret = ft_print_s2(s, fl, ret, len);
	return (ret);
}
