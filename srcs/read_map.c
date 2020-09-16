/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 16:19:37 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/02 16:19:39 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		check_position(char **map)
{
	int		i;
	int		j;
	int		position;

	i = 0;
	position = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_one_of_them(map[i][j], "SNWE\0") == 1)
				position++;
			j++;
		}
		i++;
	}
	return (position == 1 ? 1 : 0);
}

int		check_full_map(char **map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] != '1' && map[y][x] != ' ')
			{
				if (y - 1 < 0
					|| (int)ft_strlen(map[y - 1]) <= x || map[y - 1][x] == ' '
					|| y + 1 >= (int)ft_mass_len(map) || map[y][x + 1] == ' '
					|| (int)ft_strlen(map[y + 1]) <= x
					|| map[y + 1][x] == ' ' || x - 1 < 0
					|| map[y][x - 1] == ' ' || x + 1 >= (int)ft_strlen(map[y]))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

char	**read_map(int fd)
{
	int		result;
	char	*line;
	char	**map;

	map = (char **)malloc(sizeof(char *));
	map[0] = NULL;
	while ((result = get_next_line(fd, &line)) > 0)
	{
		if (line[0] != '\0')
			map = ft_realloc_mass(map, line);
		free(line);
	}
	if (line[0] != '\0')
		map = ft_realloc_mass(map, line);
	free(line);
	if (check_position(map) == 1 && check_full_map(map) == 1
	&& result != -1 && ft_one_of_them_mass(map, " 012SNWE\0") != 0)
		return (map);
	else
	{
		ft_free_array(map);
		return (NULL);
	}
}
