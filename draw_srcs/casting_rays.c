/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 19:47:14 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/18 19:47:16 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	horizontal_ray(t_vars *var, float ray_angle)
{
	t_ray	ray;

	if (ray_angle > PI)
	{
		ray.y = (int)(var->player->y_pos / 32) * 32 - 0.001;
		ray.x = var->player->x_pos + (ray.y - var->player->y_pos) /
				tan(ray_angle);
		ray.y_offset = -32;
		ray.x_offset = ray.y_offset / tan(ray_angle);
	}
	if (ray_angle < PI)
	{
		ray.y = (int)(var->player->y_pos / 32) * 32 + 32;
		ray.x = var->player->x_pos + (ray.y - var->player->y_pos) /
				tan(ray_angle);
		ray.y_offset = 32;
		ray.x_offset = ray.y_offset / tan(ray_angle);
	}
	if (ray_angle == 0 || ray_angle == PI)
	{
		ray.x = var->player->x_pos;
		ray.y = var->player->y_pos;
	}
	horizontal_ray_wall(var, &ray);
}

void	horizontal_ray_wall(t_vars *var, t_ray *ray)
{
	ray->map_x = (int)(ray->x / 32);
	ray->map_y = (int)(ray->y / 32);
	while (ray->x >= 0 && ray->y >= 0 && ray->x <
			ft_strlen(var->map[ray->map_y]) * 32 &&
			ray->y < ft_mass_len(var->map) * 32)
	{
		ray->map_x = (int)(ray->x / 32);
		ray->map_y = (int)(ray->y / 32);
		if (var->map[ray->map_y][ray->map_x] == '1')
			break ;
		ray->x += ray->x_offset;
		ray->y += ray->y_offset;
	}
	ray->length = ft_straight_len(var->player->x_pos, var->player->y_pos,
				ray->x, ray->y);
	var->hor_ray[0] = ray->length;
	var->hor_ray[1] = ray->x;
	var->hor_ray[2] = ray->y;
}

void	vertical_ray(t_vars *var, float ray_angle)
{
	t_ray	ray;

	if (ray_angle > PI / 2 && ray_angle < 3 * PI / 2)
	{
		ray.x = (int)(var->player->x_pos / 32) * 32 - 0.001;
		ray.y = var->player->y_pos + (ray.x - var->player->x_pos) *
				tan(ray_angle);
		ray.x_offset = -32;
		ray.y_offset = ray.x_offset * tan(ray_angle);
	}
	if (ray_angle < PI / 2 || ray_angle > 3 * PI / 2)
	{
		ray.x = (int)(var->player->x_pos / 32) * 32 + 32;
		ray.y = var->player->y_pos + (ray.x - var->player->x_pos) *
				tan(ray_angle);
		ray.x_offset = 32;
		ray.y_offset = ray.x_offset * tan(ray_angle);
	}
	if (ray_angle == PI / 2 || ray_angle == 3 * PI / 2)
	{
		ray.y = var->player->y_pos;
		ray.x = var->player->x_pos;
	}
	vertical_ray_wall(var, &ray);
}

void	vertical_ray_wall(t_vars *var, t_ray *ray)
{
	ray->map_x = (int)((ray->x < 0 ? 0 : ray->x) / 32);
	ray->map_y = (int)((ray->y < 0 ? 0 : ray->y) / 32);
	while (ray->x > 0 && ray->y > 0 && ray->y < ft_mass_len(var->map) * 32)
	{
		ray->map_x = (int)(ray->x / 32);
		ray->map_y = (int)(ray->y / 32);
		if (var->map[ray->map_y][ray->map_x] == '1')
			break ;
		ray->x += ray->x_offset;
		ray->y += ray->y_offset;
	}
	ray->length = ft_straight_len(var->player->x_pos,
					var->player->y_pos, ray->x, ray->y);
	var->vert_ray[0] = ray->length;
	var->vert_ray[1] = ray->x;
	var->vert_ray[2] = ray->y;
}
