/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:26:56 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/11 15:27:00 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		destroy_window(void *param)
{
	exit_game(param);
	return (0);
}

int		move(int key, t_vars *var)
{
	if (key == 53)
		exit_game(var);
	if (key == 124)
		rotate(var, 'r');
	if (key == 123)
		rotate(var, 'l');
	if (key == 0)
		move_left_right(var, 'l');
	if (key == 2)
		move_left_right(var, 'r');
	if (key == 1)
		move_up_down(var, 'd');
	if (key == 13)
		move_up_down(var, 'u');
	draw(var);
	return (1);
}
