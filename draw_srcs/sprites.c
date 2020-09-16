/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 14:56:17 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/21 14:56:19 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_sprites	*init_sprites(t_vars *var)
{
	t_sprites	*sprite;
	int			i;
	int			j;
	int			count;

	count_sprites(var);
	if (!(sprite = malloc(sizeof(t_sprites) * var->sprite_count)))
		return (NULL);
	i = -1;
	count = 0;
	while (var->map[++i] != NULL)
	{
		j = -1;
		while (var->map[i][++j] != '\0')
			if (var->map[i][j] == '2')
			{
				sprite[count].x = j;
				sprite[count].act_x = j * 32 + 16;
				sprite[count].y = i;
				sprite[count++].act_y = i * 32 + 16;
			}
	}
	return (sprite);
}

void		count_sprites(t_vars *var)
{
	int		i;
	int		j;

	i = 0;
	var->sprite_count = 0;
	while (var->map[i] != NULL)
	{
		j = 0;
		while (var->map[i][j] != '\0')
		{
			if (var->map[i][j] == '2')
			{
				var->sprite_count++;
			}
			j++;
		}
		i++;
	}
}

void		sprite_configs(t_vars *var, t_sprite_conf *spr, int i)
{
	float	sinus;

	spr->dist = var->sprite[var->sprite_order[i]].dist;
	spr->x_cam_pos = (-var->player->x_pos +
					var->sprite[var->sprite_order[i]].act_x);
	spr->y_cam_pos = (-var->player->y_pos +
					var->sprite[var->sprite_order[i]].act_y);
	spr->cosinus = (spr->x_cam_pos / spr->dist) * var->player->cos_angle +
					(spr->y_cam_pos / spr->dist) * var->player->sin_angle;
	sinus = (spr->y_cam_pos / spr->dist) * var->player->cos_angle -
			(spr->x_cam_pos / spr->dist) * var->player->sin_angle;
	spr->y_cam_pos = spr->cosinus * spr->dist;
	spr->screen_position = var->window->x_res / 2 + var->proj_plane *
							tan(asin(sinus));
	spr->height = abs((int)(var->proj_plane * 32 / spr->y_cam_pos));
	spr->y_start = (int)(var->window->y_res / 2 - spr->height / 2);
	spr->y_start = spr->y_start < 0 ? 0 : spr->y_start;
	spr->y_end = (int)(var->window->y_res / 2 + spr->height / 2);
	spr->y_end = spr->y_end >= var->window->y_res ? var->window->y_res - 1
				: spr->y_end;
	spr->width = spr->height;
	spr->x_start = (int)(spr->screen_position - spr->width / 2);
	spr->x_end = (int)(spr->screen_position + spr->width / 2);
	spr->x_end = spr->x_end > var->window->x_res ? var->window->x_res - 1 :
				spr->x_end;
}

void		draw_sprites(t_vars *var)
{
	t_sprite_conf	spr;
	int				i;
	int				stripe;
	int				y;

	i = -1;
	y = 0;
	while (++i < var->sprite_count)
	{
		sprite_configs(var, &spr, i);
		stripe = spr.x_start;
		while (stripe < spr.x_end)
		{
			if (spr.cosinus >= 0 && stripe > 0 &&
				stripe < var->window->x_res && spr.dist < var->lengthes[stripe])
			{
				spr.x_pixel_pos = (stripe - spr.x_start) *
									var->texture[4]->width / spr.width;
				y = spr.y_start;
				while (y < spr.y_end)
					print_sprite_pix(var, spr, y++, stripe);
			}
			stripe++;
		}
	}
}
