/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:15:36 by leweathe          #+#    #+#             */
/*   Updated: 2020/04/29 14:15:37 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*char_dst;
	unsigned const char	*char_src;

	char_dst = (unsigned char *)dst;
	char_src = (unsigned const char *)src;
	while (n--)
	{
		*char_dst++ = *char_src;
		if (*char_src++ == (unsigned char)c)
			return (char_dst);
	}
	return (NULL);
}
