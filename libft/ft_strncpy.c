/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:23:59 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/21 18:48:31 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*res;

	res = dst;
	while (len--)
	{
		if (*src == '\0')
			*res = '\0';
		else
		{
			*res = *(char*)src;
			src++;
		}
		res++;
	}
	return (dst);
}
