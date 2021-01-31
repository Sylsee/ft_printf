/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 11:08:49 by spoliart          #+#    #+#             */
/*   Updated: 2021/01/31 13:45:02 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

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

int		ft_print_choice(const char *format, va_list args, int fl[8])
{
	if (format[fl[0]] == 'c')
		return (ft_print_c((char)va_arg(args, char), fl);
	if (format[fl[0]] == 's')
		return (ft_print_s((char *)va_arg(args, char *), fl);
	if (format[fl[0]] == 'p')
		return (ft_print_p((unsigned long)va_arg(args, void *), fl);
	if (format[fl[0]] == 'd' || format[fl[0]] == 'i')
		return (ft_print_d((int)va_arg(args, int), fl);
	if (format[fl[0]] == 'u')
		return (ft_print_u((unsigned int)va_arg(args, unsigned int), fl);
	if (format[fl[0]] == 'x')
		return (ft_print_x((unsigned int)va_arg(args, int), fl);
	if (format[fl[0]] == 'X')
		return (ft_print_X((unsigned int)va_arg(args, int), fl);
}

void	ft_flags(const char *format, int fl[8])
{
	while (format[++fl[0]] && (format[fl[0]] == '-' || format[fl[0]] == '0'))
	{
		if (format[fl[0]] == '-' && ++fl[2])
			fl[3] = 0;
		else if (format[fl[0]] == '0' && ++fl[3] && fl[2] != 0)
			fl[3] = 0;
	}
}

void	ft_width(const char *format, va_list args, int fl[8])
{
	else if (format[fl[0]] && format[fl[0]] == '*' && ++fl[0])
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

void	ft_prec(const char *format, va_list args, int fl[8])
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

int		ft_init_printf(const char *format, va_list args)
{
	int fl[8];

	ft_memset(fl, 0, 8);
	ft_flags(format, fl);
	ft_width(format, args, fl);
	ft_prec(format, fl);
	return (ft_print_choice(format, args, fl));
}

int		ft_printf(const char *format, ...)
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
				ret += write(1, &format[i], 1) + 0 * ++i;
			else
				ret += ft_init_printf(&format[i], args);
		}
		else
			ret += write(1, &format[i], 1);
	}
	va_end(args);
	return (ret);
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	ft_printf("%% wesh");
	return (0);
}
/*
int	ft_valid_element(const char format)
{
	int			i;
	static char	*tab[11] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '-', '.', '*'};

	i = -1;
	while (++i < 11
		if (format == tab[i] || ft_isdigit(format))
			return (1);
	return (0);
}*/
