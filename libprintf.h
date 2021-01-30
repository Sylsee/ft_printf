/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 01:29:26 by spoliart          #+#    #+#             */
/*   Updated: 2020/11/30 09:48:16 by spoliart         ###   ########.fr       */
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

#endif