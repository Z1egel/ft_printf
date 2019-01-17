/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:35:47 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/26 15:30:12 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*temp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if ((res = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2))
																		+ 1)))
	{
		temp = res;
		while (*s1)
			*temp++ = *s1++;
		while (*s2)
			*temp++ = *s2++;
		*temp = '\0';
		return (res);
	}
	return (NULL);
}
