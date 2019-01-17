/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:11:06 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/24 00:24:01 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	int		flag;
	size_t	len;

	flag = 0;
	len = ft_strlen(s);
	while (len-- + 1)
	{
		if (*s == (char)c)
		{
			res = (char*)s;
			flag = 1;
		}
		s++;
	}
	if (flag)
		return (res);
	return (NULL);
}
