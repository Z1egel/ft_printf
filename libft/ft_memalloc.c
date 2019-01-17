/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:26:13 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/23 23:01:58 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ptr;
	void	*temp;

	if ((ptr = (void*)malloc(sizeof(char) * size)))
	{
		temp = ptr;
		while (size--)
			*(unsigned char*)temp++ = 0;
		return (ptr);
	}
	return (NULL);
}
