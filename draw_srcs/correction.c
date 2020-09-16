/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:13:41 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/24 16:14:15 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

float	correction(float length, float player_angle, float ray_angle)
{
	float	fish_angle;

	fish_angle = player_angle - ray_angle;
	if (fish_angle < 0)
		fish_angle += 2 * PI;
	if (fish_angle > 2 * PI)
		fish_angle -= 2 * PI;
	return (length * cos(fish_angle));
}
