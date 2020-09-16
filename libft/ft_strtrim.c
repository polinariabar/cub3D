/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 08:58:05 by leweathe          #+#    #+#             */
/*   Updated: 2020/05/05 14:31:38 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_first(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		change;
	int		first;

	i = 0;
	first = 0;
	while (s1[i])
	{
		change = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j++] && change == 0)
			{
				first++;
				change = 1;
			}
		}
		if (change == 1)
			i++;
		else
			break ;
	}
	return (first);
}

int		count_last(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		change;
	int		last;

	i = ft_strlen(s1) - 1;
	last = 0;
	while (i >= 0)
	{
		change = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j++] && change == 0)
			{
				last++;
				change = 1;
			}
		}
		if (change != 0)
			i--;
		else
			break ;
	}
	return (last);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	int		first;
	int		last;
	int		i;
	int		length;

	if (s1 == NULL || set == NULL)
		return (NULL);
	first = count_first(s1, set);
	last = count_last(s1, set);
	length = ft_strlen(s1) - first - last;
	if (length < 0)
		length = 0;
	if (!(copy = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	i = 0;
	if (length == 0)
		copy[i] = '\0';
	else
	{
		while (first != (int)ft_strlen(s1) - last)
			copy[i++] = s1[first++];
		copy[i] = '\0';
	}
	return (copy);
}
