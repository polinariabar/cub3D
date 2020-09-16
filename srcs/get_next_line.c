/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 17:38:52 by leweathe          #+#    #+#             */
/*   Updated: 2020/05/25 17:38:54 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		reading_line(char **stack, long long size, int fd)
{
	char		*tmp_stack;
	long long	ret;
	char		*buffer;

	buffer = (char *)malloc(sizeof(char) * size + 1);
	while ((ret = read(fd, buffer, size)) > 0)
	{
		buffer[ret] = '\0';
		if (*stack)
		{
			if (!(tmp_stack = ft_strdup(*stack)))
				return (-1);
			free(*stack);
			*stack = NULL;
			if (!(*stack = ft_strjoin(tmp_stack, buffer)))
				return (-1);
			free(tmp_stack);
		}
		else if (!(*stack = ft_strdup(buffer)))
			return (-1);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (ret);
}

int		save_line(char **line, char **stack, int i)
{
	char	*tmp_stack;

	if (!(*line = ft_substr(*stack, 0, i)))
		return (-1);
	if (!(tmp_stack = ft_strdup(*stack)))
		return (-1);
	free(*stack);
	if (!(*stack = ft_strdup(tmp_stack + i + 1)))
		return (-1);
	free(tmp_stack);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	long long	i;
	static char	*stack;
	long long	ret;
	int			buffer_size;

	i = 0;
	buffer_size = 10;
	if (fd < 0 || line == NULL || buffer_size <= 0)
		return (-1);
	if (ft_strchr(stack, '\n') == NULL)
		if ((ret = reading_line(&stack, buffer_size, fd)) <= 0)
		{
			if (ret == 0 && stack == NULL)
				*line = ft_strdup("\0");
			if ((ret == 0 && stack == NULL) || ret == -1)
				return (ret);
		}
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	if (stack[i] == '\n')
		return (save_line(line, &stack, i));
	*line = ft_strdup(stack);
	free(stack);
	stack = NULL;
	return (*line ? 0 : -1);
}
