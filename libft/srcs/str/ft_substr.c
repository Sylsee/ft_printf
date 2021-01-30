/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:29:23 by spoliart          #+#    #+#             */
/*   Updated: 2021/01/30 14:49:22 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret || !s || start > ft_strlen(s))
		return (ft_strdup(""));
	while (s[start + i] && i < (int)len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
