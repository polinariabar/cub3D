/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 11:42:36 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/18 11:42:38 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	if_error_exit(t_textures *name_texture, t_map_params *params,
		char **map, char code)
{
	free_textures(name_texture);
	free(params);
	ft_free_array(map);
	error(code);
	exit(0);
}

void	exit_game(t_vars *var)
{
	free(var->player);
	free_var_window(var);
	free_var_textures(var);
	ft_free_array(var->map);
	free(var->sprite);
	free(var);
	exit(0);
}
