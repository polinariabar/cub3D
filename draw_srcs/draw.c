/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:54:56 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/11 14:54:59 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	draw_floor_ceilling(t_ray_params ray, t_vars *var)
{
	float	print_params[3];

	print_params[0] = ray.ray;
	print_params[1] = ray.offset + ray.wall_height;
	print_params[2] = var->window->y_res - 1 - ray.offset - ray.wall_height;
	print_column(var, print_params, var->floor);
	print_params[1] = 0;
	print_params[2] = ray.offset;
	print_column(var, print_params, var->ceilling);
}

void	draw_walls(t_ray_params ray, t_vars *var, float *print_params)
{
	float	hint;

	hint = 1 - (var->vert_ray[2] / 32 - (int)(var->vert_ray[2] / 32));
	var->texture_index = 2;
	if (ray.vert_len > ray.hor_len && (ray.ray_angle >= 0
									&& ray.ray_angle < PI))
	{
		hint = 1 - (var->hor_ray[1] / 32 - (int)(var->hor_ray[1] / 32));
		var->texture_index = 1;
	}
	else if (ray.vert_len > ray.hor_len && (ray.ray_angle >= PI
										&& ray.ray_angle < 2 * PI))
	{
		hint = var->hor_ray[1] / 32 - (int)(var->hor_ray[1] / 32);
		var->texture_index = 0;
	}
	else if (ray.vert_len < ray.hor_len && (ray.ray_angle > 3 * PI / 2
										|| ray.ray_angle < PI / 2))
	{
		hint = var->vert_ray[2] / 32 - (int)(var->vert_ray[2] / 32);
		var->texture_index = 3;
	}
	print_walls(var, print_params, hint);
}

void	draw_column(t_vars *var, float ray_angle, int col)
{
	t_ray_params	ray;
	float			print_params[3];

	ray.ray = col;
	ray.ray_angle = ray_angle;
	vertical_ray(var, ray_angle);
	ray.vert_len = var->vert_ray[0];
	horizontal_ray(var, ray_angle);
	ray.hor_len = var->hor_ray[0];
	ray.length = ray.vert_len > ray.hor_len ? sqrtf(ray.hor_len) :
				sqrtf(ray.vert_len);
	var->lengthes[col] = ray.length;
	ray.length = correction(ray.length, var->player->angle, ray_angle);
	ray.actual_wall_height = (32 * var->proj_plane) / ray.length;
	ray.wall_height = ray.actual_wall_height >= var->window->y_res ?
					var->window->y_res - 1 : ray.actual_wall_height;
	ray.offset = (var->window->y_res - ray.wall_height) / 2;
	draw_floor_ceilling(ray, var);
	print_params[0] = ray.ray;
	print_params[1] = ray.offset;
	print_params[2] = ray.actual_wall_height;
	draw_walls(ray, var, print_params);
}

void	draw(t_vars *var)
{
	float			ray_angle;
	int				col;

	col = 0;
	var->player->cos_angle = cos(var->player->angle);
	var->player->sin_angle = sin(var->player->angle);
	ray_angle = var->player->angle - PI / 6;
	ray_angle = (ray_angle < 0 ? ray_angle + 2 * PI : ray_angle);
	ray_angle = (ray_angle > 2 * PI ? ray_angle - 2 * PI : ray_angle);
	var->proj_plane = var->window->x_res / 2 / tan(PI / 6);
	var->lengthes = malloc(sizeof(float) * var->window->x_res);
	while (col < var->window->x_res)
	{
		draw_column(var, ray_angle, col++);
		ray_angle += PI / 3 / var->window->x_res;
		ray_angle = (ray_angle < 0 ? ray_angle + 2 * PI : ray_angle);
		ray_angle = (ray_angle > 2 * PI ? ray_angle - 2 * PI : ray_angle);
	}
	sort_sprites(var);
	draw_sprites(var);
	free(var->lengthes);
	free(var->sprite_order);
	mlx_put_image_to_window(var->window->mlx, var->window->win,
							var->window->img, 0, 0);
}
