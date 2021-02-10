/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 13:50:47 by spoliart          #+#    #+#             */
/*   Updated: 2021/02/10 16:47:01 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_strup(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		ft_toupper(s[i]);
}

static char	*ft_cut(char *s, int n)
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

int			ft_print_d(long nb, int *fl)
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

int			ft_print_c(char c, int *fl)
{
	int ret;

	ret = 1;
	if (fl[5])
		ret += ft_putxchar_fd(' ', 1, fl[1] - len);
	if (fl[3])
		ret += ft_putxchar_fd('0', 1, fl[1] - len);
	ft_putchar_fd(c, 1);
	if (fl[2])
	{
		if (fl[1] < 0)
			fl[1] = -fl[1];
		ft_putxchar_fd(' ', 1, fl[1] - len);
	}
	else if ((fl[3] || fl[5]) && fl[1] < 0)
	{
		fl[1] = -fl[1];
		ft_putxchar_fd(' ', 1, fl[1] - len);
	}
	return (ret);
}

int			ft_print_s(char *s, int *fl)
{
	int ret;
	int len;

	if (fl[4] && fl[6] >= 0)
		s = ft_cut(s, fl[6]);
	len = ft_strlen(s);
	ret = len;
	if (fl[5])
		ret += ft_putxchar_fd(' ', 1, fl[1] - len);
	if (fl[3])
		ret += ft_putxchar_fd('0', 1, fl[1] - len);
	ft_putstr_fd(s, 1);
	if (fl[2])
	{
		if (fl[1] < 0)
			fl[1] = -fl[1];
		ft_putxchar_fd(' ', 1, fl[1] - len);
	}
	else if ((fl[3] || fl[5]) && fl[1] < 0)
	{
		fl[1] = -fl[1];
		ft_putxchar_fd(' ', 1, fl[1] - len);
	}
	return (ret);
}

static int	ft_print_p2(char *s, int *fl)
{
	int ret;
	int len;

	len = ft_strlen(s);
	ret = len + 2;
	if (fl[5])
		ret += ft_putxchar_fd(' ', 1, fl[1] - len - 2);
	ft_putstr_fd("0x", 1);
	if (fl[3])
		ret += ft_putxchar_fd('0', 1, fl[1] - len - 2);
	ft_putstr_fd(s, 1);
	if (fl[2])
	{
		if (fl[1] < 0)
			fl[1] = -fl[1];
		ft_putxchar_fd(' ', 1, fl[1] - len - 2);
	}
	else if ((fl[3] || fl[5]) && fl[1] < 0)
	{
		fl[1] = -fl[1];
		ft_putxchar_fd(' ', 1, fl[1] - len - 2);
	}
	return (ret);
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
		return (NULL);
	nb = n;
	if (!len)
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


static int	ft_print_x2(char *s, int *fl)
{
	int ret;
	int len;

	len = ft_strlen(s);
	ret = len;
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

int			ft_print_x(unsigned int n, int *fl, int cap)
{
	int len;
	unsigned int nb;

	nb = n;
	len = 0;
	while (nb)
		nb/= 16 + 0 * len++;
	s = (char *)malloc(sizeof(s) * (len + 1));
	if (!s)
		return (NULL);
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
	if (cap == 1)
		ft_strup(s);
	return (ft_print_x2(s, fl));
}
