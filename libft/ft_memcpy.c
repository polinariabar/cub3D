/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:16:02 by leweathe          #+#    #+#             */
/*   Updated: 2020/04/29 19:05:08 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*char_dst;
	const unsigned char	*char_src;

	char_dst = (unsigned char *)dst;
	char_src = (const unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n--)
		*char_dst++ = *char_src++;
	return (dst);
}
