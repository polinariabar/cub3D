/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:12:30 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/27 17:12:33 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

int		dot_cub(char *file)
{
	int len;

	len = ft_strlen(file) - 1;
	if (file[len] == 'b' && file[len - 1] == 'u'
		&& file[len - 2] == 'c' && file[len - 3] == '.')
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	int				fd;
	t_textures		*texture;
	t_map_params	*params;
	char			**map;
	int				screenshot;

	screenshot = 0;
	if (argc == 1 || !(dot_cub(argv[1])) || (fd = open(argv[1], O_RDONLY)) < 0)
		return (error('o'));
	if (argc == 3 && ft_strncmp(argv[2], "--save\0", 7) == 0)
		screenshot = 1;
	if (argc > 3 || (argc == 3 && ft_strncmp(argv[2], "--save\0", 7) != 0))
		return (argc > 3 ? error('n') : error('s'));
	if (!(texture = init_textures()))
		return (error('a'));
	if (!(params = init_params()))
		return (error('a'));
	if (read_configurations(fd, texture, params) < 0)
		return (error('f'));
	if (!(map = read_map(fd)))
		return (error('m'));
	close(fd);
	if (!(main_graphic(texture, params, map, screenshot)))
		return (error('a'));
}
