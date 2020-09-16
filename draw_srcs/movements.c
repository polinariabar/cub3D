/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:24:18 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/24 14:24:22 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	rotate(t_vars *var, char direction)
{
	if (direction == 'r')
	{
		var->player->angle += 0.1;
		if (var->player->angle > 2 * PI)
			var->player->angle -= 2 * PI;
	}
	else
	{
		var->player->angle -= 0.1;
		if (var->player->angle < 0)
			var->player->angle += 2 * PI;
	}
}

void	move_left_right(t_vars *var, char direction)
{
	var->player->dx = -var->player->sin_angle * 5;
	var->player->dy = var->player->cos_angle * 5;
	if (direction == 'l')
	{
		if (var->map[(int)(var->player->y_pos - var->player->dy) / 32]
			[(int)(var->player->x_pos - var->player->dx) / 32] != '1')
		{
			var->player->y_pos -= var->player->dy;
			var->player->x_pos -= var->player->dx;
		}
	}
	else
	{
		if (var->map[(int)(var->player->y_pos + var->player->dy) / 32]
			[(int)(var->player->x_pos + var->player->dx) / 32] != '1')
		{
			var->player->y_pos += var->player->dy;
			var->player->x_pos += var->player->dx;
		}
	}
}

void	move_up_down(t_vars *var, char direction)
{
	var->player->dx = var->player->cos_angle * 5;
	var->player->dy = var->player->sin_angle * 5;
	if (direction == 'd')
	{
		if (var->map[(int)(var->player->y_pos - var->player->dy) / 32]
			[(int)(var->player->x_pos - var->player->dx) / 32] != '1')
		{
			var->player->y_pos -= var->player->dy;
			var->player->x_pos -= var->player->dx;
		}
	}
	else
	{
		if (var->map[(int)(var->player->y_pos + var->player->dy) / 32]
			[(int)(var->player->x_pos + var->player->dx) / 32] != '1')
		{
			var->player->y_pos += var->player->dy;
			var->player->x_pos += var->player->dx;
		}
	}
}
