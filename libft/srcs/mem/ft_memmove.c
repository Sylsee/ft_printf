/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:26:31 by spoliart          #+#    #+#             */
/*   Updated: 2021/01/28 16:06:56 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tab;
	unsigned char	*pt_src;
	unsigned char	*pt_dst;

	i = 0;
	pt_src = (unsigned char *)src;
	pt_dst = (unsigned char *)dst;
	tab = (unsigned char *)malloc(sizeof(tab) * len);
	if (!tab || !len || src == dst)
		return (dst);
	while (i < len)
		tab[i++] = *pt_src++;
	i = 0;
	while (i < len)
		*pt_dst++ = tab[i++];
	return (dst);
}
