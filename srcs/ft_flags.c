/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:42:48 by spoliart          #+#    #+#             */
/*   Updated: 2021/02/12 14:02:45 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_flags(const char *format, int *fl)
{
	while (format[++fl[0]] && (format[fl[0]] == '-' || format[fl[0]] == '0'))
	{
		if (format[fl[0]] == '-' && ++fl[2])
			fl[3] = 0;
		else if (format[fl[0]] == '0' && ++fl[3] && fl[2] != 0)
			fl[3] = 0;
	}
}

void		ft_width(const char *format, va_list args, int *fl)
{
	if (format[fl[0]] && format[fl[0]] == '*' && ++fl[0])
	{
		if (!fl[2] && !fl[3])
			++fl[5];
		fl[1] = va_arg(args, int);
	}
	else if (format[fl[0]] && ft_isdigit(format[fl[0]]))
	{
		if (!fl[2] && !fl[3])
			++fl[5];
		fl[1] = ft_atoi(&format[fl[0]]);
		while (ft_isdigit(format[fl[0]]))
			++fl[0];
	}
}

void		ft_prec(const char *format, va_list args, int *fl)
{
	if (format[fl[0]] && format[fl[0]] == '.' && ++fl[4] && ++fl[0])
	{
		if (format[fl[0]] && format[fl[0]] == '*' && ++fl[0])
			fl[6] = va_arg(args, int);
		else if (format[fl[0]] && ft_isdigit(format[fl[0]]))
		{
			fl[6] = ft_atoi(&format[fl[0]]);
			while (ft_isdigit(format[fl[0]]))
				++fl[0];
		}
	}
}
