/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcuate_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:01:04 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/11 15:01:07 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

float	ft_straight_len(int x_start, int y_start, float x_end, float y_end)
{
	float	katet1;
	float	katet2;
	float	length;

	katet1 = (-x_start + x_end) * (-x_start + x_end);
	katet2 = (-y_start + y_end) * (-y_start + y_end);
	length = katet1 + katet2;
	return (length);
}
