/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:15:49 by leweathe          #+#    #+#             */
/*   Updated: 2020/04/30 11:12:17 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*chars;
	size_t				i;

	i = 0;
	chars = (const unsigned char *)s;
	while (i != n)
	{
		if (chars[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
