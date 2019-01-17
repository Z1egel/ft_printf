/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:18:12 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/25 22:02:15 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dst_len;
	size_t		len;
	char		*tmp;
	const char	*str;

	tmp = dst;
	len = size;
	str = src;
	while (len-- != 0 && *tmp)
		tmp++;
	dst_len = tmp - dst;
	len = size - dst_len;
	if (len == 0)
		return (dst_len + ft_strlen(src));
	while (*str)
	{
		if (len != 1)
		{
			*tmp++ = *(char*)str;
			len--;
		}
		str++;
	}
	*tmp = '\0';
	return (dst_len + (str - src));
}
