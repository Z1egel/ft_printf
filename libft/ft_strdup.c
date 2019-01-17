/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:27:51 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/20 19:32:55 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	length;
	char	*s2;

	length = 0;
	while (s1[length])
		length++;
	if ((s2 = (char*)malloc(sizeof(*s1) * (length + 1))))
	{
		length = 0;
		while (s1[length])
		{
			s2[length] = s1[length];
			length++;
		}
		s2[length] = '\0';
	}
	else
		return (NULL);
	return (s2);
}
