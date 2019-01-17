/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 02:43:00 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/26 17:18:28 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	while (*alst)
	{
		del((*alst)->content, sizeof((*alst)->content));
		free(*alst);
		*alst = (*alst)->next;
	}
	*alst = NULL;
}
