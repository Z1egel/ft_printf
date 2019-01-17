/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:12:26 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/25 17:13:56 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*tmp;

	tmp = dst;
	if (src < dst && dst < src + len)
	{
		src = src + len;
		dst = dst + len;
		while (len--)
			*(unsigned char*)--dst = *(unsigned char*)--src;
	}
	else
		while (len--)
			*(unsigned char*)dst++ = *(unsigned char*)src++;
	return (tmp);
}
