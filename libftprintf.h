/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 01:29:26 by spoliart          #+#    #+#             */
/*   Updated: 2021/02/10 16:42:38 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PRINTF
# define LIB_PRINTF

# include <stdarg.h>
# include "libft/includes/libft.h"

typedef struct	s_arg
{
	char	*flags;
	char	type;
	int		prec;
	int		width;
	int		space;
}				t_arg;

int	ft_printf(const char *format, ...);
int	ft_print_d(long nb, int *fl);
int	ft_print_c(char c, int *fl);
int	ft_print_s(char *s, int *fl);
int	ft_print_p(unsigned long n, int *fl);
int	ft_print_x(unsigned int n, int *fl, int cap);

#endif