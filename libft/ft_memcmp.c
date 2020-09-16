/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:11:20 by leweathe          #+#    #+#             */
/*   Updated: 2020/04/30 11:12:33 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*chars1;
	const unsigned char	*chars2;

	i = 0;
	chars1 = (const unsigned char *)s1;
	chars2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (chars1[i] == chars2[i])
			i++;
		else
			return (chars1[i] - chars2[i]);
	}
	return (0);
}
