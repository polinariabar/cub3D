/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 09:41:41 by leweathe          #+#    #+#             */
/*   Updated: 2020/04/30 09:54:47 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*mass;

	i = 0;
	mass = (char *)malloc(count * size);
	if (mass == NULL)
		return (NULL);
	while (i != count * size)
		((char *)mass)[i++] = '\0';
	return (mass);
}
