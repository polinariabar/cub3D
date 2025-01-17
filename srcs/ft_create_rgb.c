/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 11:30:47 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/15 11:30:49 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_create_rgb(int r, int g, int b)
{
	if (r > 255 || r < 0 || g > 255
				|| g < 0 || b > 255 || b < 0)
		return (-1);
	return (r << 16 | g << 8 | b);
}
