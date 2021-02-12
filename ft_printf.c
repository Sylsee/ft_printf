/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 11:08:49 by spoliart          #+#    #+#             */
/*   Updated: 2021/02/12 16:29:31 by spoliart         ###   ########.fr       */
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
	if (format[fl[0]] == 'c')
		return (ft_print_c((char)va_arg(args, int), fl));
	if (format[fl[0]] == 's')
		return (ft_print_s((char *)va_arg(args, char *), fl));
	if (format[fl[0]] == 'p')
		return (ft_print_p((unsigned long)va_arg(args, void *), fl));
	if (format[fl[0]] == 'd' || format[fl[0]] == 'i')
		return (ft_print_d((long)va_arg(args, int), fl));
	if (format[fl[0]] == 'u')
		return (ft_print_d((long)va_arg(args, unsigned int), fl));
	if (format[fl[0]] == 'x')
		return (ft_print_x((unsigned int)va_arg(args, int), fl, 0));
	if (format[fl[0]] == 'X')
		return (ft_print_x((unsigned int)va_arg(args, int), fl, 1));
	return (0);
}

static int		ft_init_printf(const char *format, va_list args)
{
	int *fl;

	fl = (int *)malloc(sizeof(fl) * 8);
	if (!fl)
		return (0);
	ft_memset(fl, 0, 8);
	ft_flags(format, fl);
	ft_width(format, args, fl);
	ft_prec(format, args, fl);
	ret = ft_print_choice(format, args, fl);
	while (ft_valid_elem(format[i]))
	return (ret);
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
				ret += ft_init_printf(&format[i], args);
		}
		else
			ret += write(1, &format[i], 1);
	}
	va_end(args);
	return (ret);
}
