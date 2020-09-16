/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 13:38:41 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/28 13:38:43 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	free_var_window(t_vars *var)
{
	mlx_destroy_image(var->window->mlx, var->window->img);
	mlx_destroy_window(var->window->mlx, var->window->win);
	free(var->window->mlx);
	free(var->window);
}

void	free_var_textures(t_vars *var)
{
	int i;

	i = 0;
	while (i < 5)
	{
		free(var->texture[i]->img_ptr);
		free(var->texture[i]->img_addr);
		free(var->texture[i]);
		i++;
	}
	free(var->texture);
}
