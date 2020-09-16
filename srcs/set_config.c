/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 17:51:19 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/25 17:51:21 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		all_numbers(char **list)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		j = 0;
		while (list[i][j])
		{
			if (list[i][j] != ',' && ft_isdigit(list[i][j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int		set_textures(char **list, t_textures *texture, char *flag)
{
	if (ft_mass_len(list) == 2 && *flag != 't' && *flag != 'b')
	{
		if (!(ft_strncmp(list[0], "NO\0", 3)) && !(texture->no))
			texture->no = ft_strdup(list[1]);
		else if (!(ft_strncmp(list[0], "SO\0", 3)) && !(texture->so))
			texture->so = ft_strdup(list[1]);
		else if (!(ft_strncmp(list[0], "WE\0", 3)) && !(texture->we))
			texture->we = ft_strdup(list[1]);
		else if (!(ft_strncmp(list[0], "EA\0", 3)) && !(texture->ea))
			texture->ea = ft_strdup(list[1]);
		else if (!(ft_strncmp(list[0], "S\0", 2)) && !(texture->s))
			texture->s = ft_strdup(list[1]);
		else
			return (-1);
	}
	else
		return (-1);
	if (texture->no && texture->we && texture->so && texture->ea && texture->s)
		*flag = (*flag == 'p' ? 'b' : 't');
	return (1);
}

int		set_ceilling(char **list, t_map_params *params, int len)
{
	char	**colors_list;
	size_t	red;
	size_t	green;
	size_t	blue;

	if ((len != 4 && len != 2) || ft_strncmp(list[0], "C\0", 2)
		|| params->ceilling[0])
		return (-2);
	colors_list = (len == 2 ? ft_split(list[1], ',') : NULL);
	if (colors_list != NULL && ft_mass_len(colors_list) != 3)
	{
		ft_free_array(colors_list);
		return (-2);
	}
	if (all_numbers(len == 2 ? colors_list : list + 1) == -1)
		return (-2);
	red = ft_atoi(len == 2 ? colors_list[0] : list[1]);
	green = ft_atoi(len == 2 ? colors_list[1] : list[2]);
	blue = ft_atoi(len == 2 ? colors_list[2] : list[3]);
	if (colors_list)
		ft_free_array(colors_list);
	params->ceilling[0] = 1;
	params->ceilling[1] = ft_create_rgb(red, green, blue);
	return (params->ceilling[1] != -1 ? 1 : -2);
}

int		set_floor(char **list, t_map_params *params, int len)
{
	char	**colors_list;
	size_t	red;
	size_t	green;
	size_t	blue;

	if ((len != 4 && len != 2) || ft_strncmp(list[0], "F\0", 2)
		|| params->floor[0])
		return (-2);
	colors_list = (len == 2 ? ft_split(list[1], ',') : NULL);
	if (colors_list != NULL && ft_mass_len(colors_list) != 3)
	{
		ft_free_array(colors_list);
		return (-2);
	}
	if (all_numbers(len == 2 ? colors_list : list + 1) == -1)
		return (-2);
	red = ft_atoi(len == 2 ? colors_list[0] : list[1]);
	green = ft_atoi(len == 2 ? colors_list[1] : list[2]);
	blue = ft_atoi(len == 2 ? colors_list[2] : list[3]);
	if (colors_list)
		ft_free_array(colors_list);
	params->floor[0] = 1;
	params->floor[1] = ft_create_rgb(red, green, blue);
	return (params->floor[1] != -1 ? 1 : -2);
}

int		set_resolution(char **list, t_map_params *params, int len)
{
	int		x;
	int		y;

	if (len == 3 && !(ft_strncmp(list[0], "R\0", 2))
				&& !(params->resolution[0]))
	{
		x = 0;
		while (list[1][x])
			if (ft_isdigit(list[1][x++]) == 0)
				return (-1);
		x = 0;
		while (list[2][x])
			if (ft_isdigit(list[2][x++]) == 0)
				return (-1);
		params->resolution[0] = 1;
		x = ft_atoi(list[1]);
		y = ft_atoi(list[2]);
		x = x > 1440 ? 1440 : x;
		y = y > 854 ? 854 : y;
		params->resolution[1] = x < 100 ? 100 : x;
		params->resolution[2] = y < 100 ? 100 : y;
		return (1);
	}
	else
		return (-2);
}
