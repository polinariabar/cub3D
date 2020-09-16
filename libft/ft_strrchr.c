/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:19:04 by leweathe          #+#    #+#             */
/*   Updated: 2020/04/30 17:38:47 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		freq;
	char	charc;
	int		yes;

	i = 0;
	freq = 0;
	yes = 0;
	charc = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == charc)
		{
			yes++;
			freq = i;
		}
		i++;
	}
	if (c == 0)
		return ((char*)s + i);
	else if (yes != 0)
		return ((char*)s + freq);
	else
		return (NULL);
}
