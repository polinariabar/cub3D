/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:18:23 by leweathe          #+#    #+#             */
/*   Updated: 2020/04/30 10:55:09 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *havstack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)havstack);
	while (i != len)
	{
		n = 0;
		while (((i + n) != len) && (havstack[i + n] == needle[n]))
		{
			n++;
			if (needle[n] == '\0')
				return ((char *)havstack + i);
			if (havstack[i + n] == '\0')
				break ;
		}
		i++;
	}
	return (NULL);
}
