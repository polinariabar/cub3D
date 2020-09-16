/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:16:52 by leweathe          #+#    #+#             */
/*   Updated: 2020/04/29 14:16:54 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	charc;

	i = 0;
	charc = (char)c;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == charc)
			return ((char *)s + i);
		i++;
	}
	if (c == 0)
		return ((char *)s + i);
	else
		return (NULL);
}
