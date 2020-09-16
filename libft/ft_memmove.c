/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:16:20 by leweathe          #+#    #+#             */
/*   Updated: 2020/05/01 11:19:26 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*char_dst;
	const char	*char_src;
	size_t		i;

	char_dst = (char *)dst;
	char_src = (const char *)src;
	i = 0;
	if (src == NULL && dst == NULL)
		return (NULL);
	if (dst < src)
		while (len--)
		{
			char_dst[i] = char_src[i];
			i++;
		}
	else
	{
		i = len - 1;
		while (len--)
		{
			char_dst[i] = char_src[i];
			i--;
		}
	}
	return (dst);
}
