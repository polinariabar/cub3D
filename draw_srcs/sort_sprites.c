/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:05:57 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/24 14:05:59 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	sort_sprites_2(t_vars *var, float *dist)
{
	int		i;
	float	tmp_dist;
	int		tmp_order;

	i = -1;
	while (++i < var->sprite_count - 1)
	{
		if (dist[i] < dist[i + 1])
		{
			tmp_dist = dist[i];
			dist[i] = dist[i + 1];
			dist[i + 1] = tmp_dist;
			tmp_order = var->sprite_order[i];
			var->sprite_order[i] = var->sprite_order[i + 1];
			var->sprite_order[i + 1] = tmp_order;
			i = -1;
		}
	}
}

void	sort_sprites(t_vars *var)
{
	float	dist[var->sprite_count];
	int		i;

	i = 0;
	if (!(var->sprite_order = malloc(sizeof(int) * var->sprite_count)))
	{
		error('a');
		exit_game(var);
	}
	while (i < var->sprite_count)
	{
		dist[i] = ((var->player->x_pos - var->sprite[i].act_x) *
				(var->player->x_pos - var->sprite[i].act_x)) +
				((var->player->y_pos - var->sprite[i].act_y) *
				(var->player->y_pos - var->sprite[i].act_y));
		var->sprite_order[i] = i;
		var->sprite[i].dist = sqrtf(dist[i]);
		i++;
	}
	sort_sprites_2(var, dist);
}
