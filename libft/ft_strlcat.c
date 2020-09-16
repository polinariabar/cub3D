/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:17:16 by leweathe          #+#    #+#             */
/*   Updated: 2020/05/02 13:07:02 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	length;

	i = 0;
	j = 0;
	length = ft_strlen(dst);
	while (dst[i] && (i != dstsize))
		i++;
	if (dstsize > length)
	{
		while (src[j] && (i + j != dstsize - 1))
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	return (i + ft_strlen(src));
}
