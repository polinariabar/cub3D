/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_massege.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:02:46 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/25 19:02:48 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		error(char type)
{
	if (type == 'o')
		ft_putstr_fd("Error\nUnable to open .cub file!\n", 1);
	if (type == 'a')
		ft_putstr_fd("Error\nAllocation problem!\n", 1);
	if (type == 'f')
		ft_putstr_fd("Error\nMisconfigurations in file!\n", 1);
	if (type == 'm')
		ft_putstr_fd("Error\nInvalid map!\n", 1);
	if (type == 't')
		ft_putstr_fd("Error\nUnable to open textures!\n", 1);
	if (type == 's')
		ft_putstr_fd("Error\nUnable to make a screenshot!\n", 1);
	if (type == 'n')
		ft_putstr_fd("Error\nInvalid number of arguments!\n", 1);
	return (0);
}
