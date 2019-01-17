/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 03:18:34 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/25 22:29:40 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*temp;
	t_list		*new_list;
	t_list		*elem;

	if (!lst)
		return (NULL);
	elem = f(lst);
	if (!(temp = ft_lstnew(elem->content, elem->content_size)))
		return (NULL);
	lst = lst->next;
	new_list = temp;
	while (lst)
	{
		elem = f(lst);
		if (!(temp->next = ft_lstnew(elem->content, elem->content_size)))
			return (NULL);
		temp = temp->next;
		lst = lst->next;
	}
	return (new_list);
}
