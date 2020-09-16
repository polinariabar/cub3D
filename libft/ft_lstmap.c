/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 16:23:41 by leweathe          #+#    #+#             */
/*   Updated: 2020/05/05 17:43:19 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*cur_elem;
	t_list	*next_elem;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	newlst = ft_lstnew((*f)(lst->content));
	if (newlst == NULL)
		return (NULL);
	cur_elem = newlst;
	lst = lst->next;
	while (lst)
	{
		next_elem = ft_lstnew((*f)(lst->content));
		if (next_elem == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		cur_elem->next = next_elem;
		cur_elem = next_elem;
		lst = lst->next;
	}
	return (newlst);
}
