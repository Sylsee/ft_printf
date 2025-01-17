/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 01:29:26 by spoliart          #+#    #+#             */
/*   Updated: 2021/02/20 14:14:40 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"

typedef struct	s_arg
{
	char		*flags;
	char		type;
	int			prec;
	int			width;
	int			space;
}				t_arg;

int				ft_printf(const char *format, ...);

void			ft_flags(const char *format, int *fl);
void			ft_width(const char *format, va_list args, int *fl);
void			ft_prec(const char *format, va_list args, int *fl);

char			*ft_strup(char *s);
char			*ft_cut(char *s, int n);
void			ft_ternary(int *fl, int *ret, int len);

int				ft_print_d(long nb, int *fl);
int				ft_print_c(char c, int *fl);
int				ft_print_s(char *s, int *fl);
int				ft_print_p(unsigned long n, int *fl);
int				ft_print_x(unsigned int n, int *fl, int cap);

#endif
