/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:15:10 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/04 17:15:12 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		display(t_vars *var)
{
	mlx_hook(var->window->win, 2, 1L << 0, move, var);
	return (0);
}

void	create_win_img(t_vars *var)
{
	var->window->mlx = mlx_init();
	var->window->win = mlx_new_window(var->window->mlx, var->window->x_res,
											var->window->y_res, "CUB3D");
	var->window->img = mlx_new_image(var->window->mlx, var->window->x_res,
											var->window->y_res);
	var->window->img_addr = mlx_get_data_addr(var->window->img,
											&var->window->bits_per_pixel,
											&var->window->line_length,
											&var->window->endian);
}

t_vars	*init_game(t_textures *name_texture, t_map_params *params, char **map)
{
	t_vars *var;

	if (!(var = init_var_struct(map, *params)))
		if_error_exit(name_texture, params, map, 'a');
	if (!(var->window = init_win_struct(*params)))
	{
		free(var);
		if_error_exit(name_texture, params, map, 'a');
	}
	if (!(var->player = init_player_struct(map)))
	{
		free(var->window);
		free(var);
		if_error_exit(name_texture, params, map, 'a');
	}
	if (!(var->sprite = init_sprites(var)))
	{
		free(var->player);
		free(var->window);
		free(var);
		if_error_exit(name_texture, params, map, 'a');
	}
	return (var);
}

int		main_graphic(t_textures *name_texture, t_map_params *params, char **map,
					int screenshot)
{
	t_vars	*var;

	var = init_game(name_texture, params, map);
	create_win_img(var);
	if (!(init_var_textures(var, name_texture)))
	{
		free(var->player);
		free_var_window(var);
		free(var->sprite);
		free(var);
		if_error_exit(name_texture, params, map, 0);
	}
	draw(var);
	free_textures(name_texture);
	free(params);
	if (screenshot)
		make_screenshot(var);
	mlx_hook(var->window->win, 17, 1L << 17, destroy_window, var);
	mlx_loop_hook(var->window->mlx, display, var);
	mlx_loop(var->window->mlx);
	return (2);
}
