/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:32:16 by spoliart          #+#    #+#             */
/*   Updated: 2021/01/25 16:59:59 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	s_len;
	unsigned int	d_len;
	unsigned int	i;

	i = 0;
	s_len = 0;
	d_len = 0;
	s_len = ft_strlen(src);
	d_len = ft_strlen(dest);
	if (size <= d_len)
		return (size + s_len);
	i = 0;
	while (size && (size-- - d_len - 1) && src[i])
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (s_len + d_len);
}
