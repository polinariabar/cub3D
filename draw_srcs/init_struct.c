/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:29:29 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/11 15:29:30 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_player	*init_player_struct(char **map)
{
	int			x;
	int			y;
	t_player	*player;

	if (!(player = malloc(sizeof(t_player))))
		return (NULL);
	if (ft_one_of_them_mass(map, "SWNE\0") == 0)
	{
		ft_one_of_them_coord(map, "SWNE\0", &x, &y);
		player->x_pos = x * 32 + 16;
		player->y_pos = y * 32 + 16;
		if (map[y][x] == 'S')
			player->angle = PI / 2;
		else if (map[y][x] == 'E')
			player->angle = 0;
		else if (map[y][x] == 'W')
			player->angle = PI;
		else
			player->angle = 3 * PI / 2;
	}
	player->cos_angle = cos(player->angle);
	player->sin_angle = sin(player->angle);
	return (player);
}

t_image		*init_texture(t_vars *var, char *texture_name)
{
	t_image		*texture;

	if (!(texture = malloc(sizeof(t_image))))
	{
		free(texture);
		return (error('a') ? NULL : NULL);
	}
	if (!(texture->img_ptr = mlx_xpm_file_to_image(var->window->mlx,
		texture_name, &texture->width, &texture->height)))
	{
		free(texture->img_ptr);
		free(texture);
		return (error('t') ? NULL : NULL);
	}
	texture->img_addr = mlx_get_data_addr(texture->img_ptr,
						&texture->bpp, &texture->line_length, &texture->endian);
	return (texture);
}

t_vars		*init_var_struct(char **map, t_map_params params)
{
	t_vars	*var;

	if (!(var = malloc(sizeof(t_vars))))
		return (NULL);
	var->map = map;
	var->floor = params.floor[1];
	var->ceilling = params.ceilling[1];
	return (var);
}

t_window	*init_win_struct(t_map_params params)
{
	t_window	*win;

	if (!(win = malloc(sizeof(t_window))))
		return (NULL);
	win->x_res = params.resolution[1];
	win->y_res = params.resolution[2];
	return (win);
}

int			init_var_textures(t_vars *var, t_textures *name_texture)
{
	int i;

	i = 0;
	var->texture = malloc(sizeof(t_image *) * 5);
	while (i < 5)
		var->texture[i++] = NULL;
	if ((var->texture[0] = init_texture(var, name_texture->no)) == NULL
		|| (var->texture[1] = init_texture(var, name_texture->so)) == NULL
		|| (var->texture[2] = init_texture(var, name_texture->we)) == NULL
		|| (var->texture[3] = init_texture(var, name_texture->ea)) == NULL
		|| (var->texture[4] = init_texture(var, name_texture->s)) == NULL)
	{
		i = 0;
		while (i < 5 && var->texture[i] != NULL)
		{
			free(var->texture[i]->img_addr);
			free(var->texture[i]->img_ptr);
			free(var->texture[i++]);
		}
		free(var->texture);
		return (0);
	}
	return (1);
}
