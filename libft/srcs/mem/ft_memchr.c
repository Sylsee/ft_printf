/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:24:32 by spoliart          #+#    #+#             */
/*   Updated: 2020/10/24 00:10:08 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *pt;

	pt = (unsigned char *)s;
	while (n--)
	{
		if (*pt == (unsigned char)c)
			return (pt);
		pt++;
	}
	return (NULL);
}
