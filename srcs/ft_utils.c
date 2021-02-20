/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:45:19 by spoliart          #+#    #+#             */
/*   Updated: 2021/02/20 01:31:01 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_strup(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		ft_toupper(s[i]);
}

char	*ft_cut(char *s, int n)
{
	int		i;
	char	*ret;

	i = -1;
	ret = (char *)malloc(sizeof(char) * n + 1);
	if (!ret)
		return (NULL);
	while (s[++i] && n--)
		ret[i] = s[i];
	ret[i] = 0;
	return (ret);
}

void	ft_ternary(int *fl, int *ret, int len)
{
	if (fl[6] > len)
		*ret += ft_putxchar_fd(' ', 1, fl[1] - fl[6] - fl[8]);
	else
		*ret += ft_putxchar_fd(' ', 1, fl[1] - len - fl[8]);
}
