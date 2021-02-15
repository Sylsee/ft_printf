/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 11:08:49 by spoliart          #+#    #+#             */
/*   Updated: 2021/02/14 23:31:13 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

/*
**  cspdiuxX%
**	fl : 0 -> between % and fl
**	fl : 1 -> digit before (width / padding)
**	fl : 2 -> number -
**	fl : 3 -> number 0
**	fl : 4 -> number .
**	fl : 5 -> number *
**	fl : 6 -> digit after (precision)
*/

static int		ft_print_choice(const char *format, va_list args, int *fl)
{
	int ret;

	ret = 0;
	if (format[fl[0]] == 'c')
		ret = ft_print_c((char)va_arg(args, int), fl);
	else if (format[fl[0]] == 's')
		ret = ft_print_s((char *)va_arg(args, char *), fl);
	else if (format[fl[0]] == 'p')
		ret = ft_print_p((unsigned long)va_arg(args, void *), fl);
	else if (format[fl[0]] == 'd' || format[fl[0]] == 'i')
		ret = ft_print_d((long)va_arg(args, int), fl);
	else if (format[fl[0]] == 'u')
		ret = ft_print_d((long)va_arg(args, unsigned int), fl);
	else if (format[fl[0]] == 'x')
		ret = ft_print_x((unsigned int)va_arg(args, int), fl, 0);
	else if (format[fl[0]] == 'X')
		ret = ft_print_x((unsigned int)va_arg(args, int), fl, 1);
	free(fl);
	return (ret);
}

static int		ft_init_printf(const char *format, va_list args, int *i)
{
	int *fl;

	fl = (int *)malloc(sizeof(fl) * 8);
	if (!fl)
		return (0);
	ft_memset(fl, 0, 8);
	ft_flags(format, fl);
	ft_width(format, args, fl);
	ft_prec(format, args, fl);
	*i = *i + fl[0];
	return (ft_print_choice(format, args, fl));
}

int				ft_printf(const char *format, ...)
{
	int		i;
	int		ret;
	va_list	args;

	i = -1;
	ret = 0;
	va_start(args, format);
	if (!format)
		return (0);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] && format[i + 1] == '%')
				ret += write(1, &format[++i], 1);
			else
				ret += ft_init_printf(&format[i], args, &i);
		}
		else
			ret += write(1, &format[i], 1);
	}
	va_end(args);
	return (ret);
}
