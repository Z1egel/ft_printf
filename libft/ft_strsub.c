/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:25:00 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/26 15:28:56 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char	*temp;

	if (s == NULL)
		return (NULL);
	if ((res = (char*)malloc(sizeof(*s) * len + 1)))
	{
		temp = res;
		while (len--)
			*temp++ = s[start++];
		*temp = '\0';
		return (res);
	}
	return (NULL);
}
