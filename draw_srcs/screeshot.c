/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screeshot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 12:43:06 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/25 12:43:08 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	int_to_char(unsigned char *c, int i)
{
	c[0] = (unsigned char)(i);
	c[1] = (unsigned char)(i >> 8);
	c[2] = (unsigned char)(i >> 16);
	c[3] = (unsigned char)(i >> 24);
}

int		bmp_header(int fd, int h, int w, int padsize)
{
	unsigned char	header[54];
	int				filesize;

	filesize = 54 + (w * 3 * h) + (padsize * h);
	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	int_to_char(header + 2, filesize);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	int_to_char(header + 18, w);
	int_to_char(header + 22, h);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	return (!(write(fd, header, 54) < 0));
}

int		get_color(t_vars *var, int x, int y)
{
	int rgb;
	int color;

	color = *(int *)(var->window->img_addr + (4 * (int)var->window->x_res
			* ((int)var->window->y_res - 1 - y)) + (4 * x));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

int		draw_screenshot(t_vars *var, int padsize, int fd)
{
	int				x;
	int				y;
	unsigned char	zero[3];
	int				color;

	y = 0;
	ft_bzero(zero, 3);
	while (y < var->window->y_res)
	{
		x = 0;
		while (x < var->window->x_res)
		{
			color = get_color(var, x, y);
			if (write(fd, &color, 3) < 0)
				return (0);
			if (padsize > 0 && write(fd, &zero, padsize) < 0)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int		make_screenshot(t_vars *var)
{
	int fd;
	int padsize;
	int filesize;

	padsize = (4 - ((int)var->window->x_res * 3) % 4) % 4;
	filesize = 54 + (3 * ((int)var->window->x_res + padsize)
					* (int)var->window->y_res);
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0777
									| O_TRUNC | O_APPEND)) < 0)
	{
		error('s');
		exit_game(var);
	}
	bmp_header(fd, var->window->y_res, var->window->x_res, padsize);
	draw_screenshot(var, padsize, fd);
	close(fd);
	exit_game(var);
	return (0);
}
