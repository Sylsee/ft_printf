/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:25:35 by spoliart          #+#    #+#             */
/*   Updated: 2021/01/25 18:02:19 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*pt_src;
	unsigned char	*pt_dst;
	unsigned char	pt_c;

	pt_src = (unsigned char *)src;
	pt_dst = (unsigned char *)dst;
	pt_c = (unsigned char)c;
	while (n-- && *pt_src != pt_c)
		*pt_dst++ = *pt_src++;
	if (*pt_src == pt_c)
	{
		*pt_dst++ = *pt_src;
		return (pt_dst);
	}
	return (NULL);
}
