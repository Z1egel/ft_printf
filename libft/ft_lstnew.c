/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 01:37:51 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/24 03:11:33 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if ((list = malloc(sizeof(t_list))))
	{
		if (content == NULL)
		{
			list->content = NULL;
			list->content_size = 0;
		}
		else
		{
			list->content = ft_memalloc(content_size);
			ft_memcpy(list->content, content, content_size);
			list->content_size = content_size;
		}
		list->next = NULL;
		return (list);
	}
	return (NULL);
}
