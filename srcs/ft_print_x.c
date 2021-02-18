/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:56:26 by spoliart          #+#    #+#             */
/*   Updated: 2021/02/18 14:31:46 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_print_x3(int *fl, int ret, int len)
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

static int	ft_print_x2(char *s, int *fl, int cap)
{
	int	ret;
	int	len;

	len = ft_strlen(s);
	ret = len;
	if (cap == 1)
		ft_strup(s);
	if ((fl[4] && (fl[3] || fl[5])) || fl[5])
		ret += ft_putxchar_fd(' ', 1, fl[1] - fl[6] - len);
	if (fl[3] || fl[4])
		ret += ft_putxchar_fd('0', 1, fl[6] - len);
	ft_putstr_fd(s, 1);
	if (fl[2])
	{
		if (fl[1] < 0)
			fl[1] = -fl[1];
		ret += ft_putxchar_fd(' ', 1, fl[1] - fl[6] - len);
	}
	free(s);
	return (ft_print_x3(fl, ret, len));
}

int			ft_print_x(unsigned int n, int *fl, int cap)
{
	char			*s;
	int				len;
	unsigned int	nb;

	nb = n;
	len = 0;
	while (nb)
		nb /= 16 + 0 * len++;
	s = (char *)malloc(sizeof(s) * (len + 1));
	if (!s)
		return (-1);
	nb = n;
	if (!len)
		s[len++] = '0';
	s[len] = '\0';
	while (len--)
	{
		if (nb % 16 < 10)
			s[len] = nb % 16 + 48;
		else
			s[len] = nb % 16 + 87;
		nb /= 16;
	}
	return (ft_print_x2(s, fl, cap));
}
