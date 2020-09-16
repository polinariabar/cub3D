/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_strucures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:54:08 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/02 14:54:09 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			free_textures(t_textures *texture)
{
	free(texture->ea);
	free(texture->no);
	free(texture->s);
	free(texture->so);
	free(texture->we);
	free(texture);
}

int				free_config(char *line, char **parsed_line,
				t_textures *texture, t_map_params *params)
{
	free(line);
	ft_free_array(parsed_line);
	free_textures(texture);
	free(params);
	return (-1);
}

t_textures		*init_textures(void)
{
	t_textures *texture;

	if (!(texture = malloc(sizeof(t_textures))))
		return (NULL);
	texture->no = NULL;
	texture->so = NULL;
	texture->we = NULL;
	texture->ea = NULL;
	texture->s = NULL;
	return (texture);
}

t_map_params	*init_params(void)
{
	t_map_params *params;

	if (!(params = malloc(sizeof(t_map_params))))
		return (NULL);
	params->resolution[0] = 0;
	params->floor[0] = 0;
	params->ceilling[0] = 0;
	return (params);
}
