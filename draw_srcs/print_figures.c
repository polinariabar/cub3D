/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:12:50 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/11 15:12:52 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		get_color_flom_texture(t_vars *var, int numb, int x, int y)
{
	char	*dst;

	y = y < 0 ? 0 : y;
	dst = var->texture[numb]->img_addr + (y * var->texture[numb]->line_length
										+ x * (var->texture[numb]->bpp / 8));
	return (*(unsigned int *)dst);
}

void	print_sprite_pix(t_vars *var, t_sprite_conf spr, int y, int stripe)
{
	int		color;

	color = 0;
	spr.y_pixel_pos = (spr.height - var->window->y_res) / 2 + y;
	spr.y_pixel_pos = spr.y_pixel_pos / spr.height * var->texture[4]->height;
	color = get_color_flom_texture(var, 4, spr.x_pixel_pos,
			(int)spr.y_pixel_pos);
	if ((color & 0x00FFFFFF) != 0)
		print_pix(var, stripe, y, color);
}

void	print_pix(t_vars *var, int x_start, int y_start, int color)
{
	int		x;
	int		y;
	char	*dst;

	x = x_start;
	y = y_start;
	dst = var->window->img_addr + (y * var->window->line_length
						+ x * (var->window->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_column(t_vars *var, float *params, int color)
{
	int		len;

	len = 0;
	while (len <= (int)params[2])
	{
		print_pix(var, params[0], params[1] + len, color);
		len++;
	}
}

void	print_walls(t_vars *var, float *print_params, float hint)
{
	int		color;
	float	x_pixel_pos;
	float	y_pixel_pos;
	int		y;

	y = print_params[1];
	x_pixel_pos = var->texture[var->texture_index]->width * hint;
	while (y < print_params[1] + print_params[2] && y < var->window->y_res)
	{
		y_pixel_pos = (print_params[2] - var->window->y_res) / 2 + y;
		y_pixel_pos = y_pixel_pos / print_params[2]
					* var->texture[var->texture_index]->height;
		color = get_color_flom_texture(var, var->texture_index,
									(int)x_pixel_pos, (int)y_pixel_pos);
		print_pix(var, print_params[0], y, color);
		y++;
	}
}
