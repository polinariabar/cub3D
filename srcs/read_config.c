/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 16:15:15 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/02 16:15:18 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		set_params(char **list, t_map_params *params, char *flag)
{
	int len;
	int floor;
	int ceilling;
	int res;

	len = ft_mass_len(list);
	floor = 0;
	if ((res = set_resolution(list, params, len)) == -2)
		if ((floor = set_floor(list, params, len)) == -2)
			if ((ceilling = set_ceilling(list, params, len)) == -2)
				return (-1);
	if (floor == -1 || ceilling == -1 || res == -1)
		return (-1);
	if (params->resolution[0] && params->floor[0] && params->ceilling[0])
		*flag = (*flag == 't' ? 'b' : 'p');
	return (1);
}

int		read_configurations(int fd, t_textures *texture, t_map_params *params)
{
	char	*line;
	char	**parsed_line;
	char	flag;

	flag = 0;
	while (flag != 'b' && get_next_line(fd, &line) > 0)
	{
		parsed_line = ft_split(line, ' ');
		if (line[0] != '\0')
			if (set_textures(parsed_line, texture, &flag) < 0)
				if (set_params(parsed_line, params, &flag) < 0)
					return (free_config(line, parsed_line, texture, params));
		free(line);
		ft_free_array(parsed_line);
	}
	if (flag != 'b')
	{
		free_textures(texture);
		free(params);
		return (-1);
	}
	return (1);
}
