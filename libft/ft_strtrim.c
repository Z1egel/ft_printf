/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:35:10 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/27 14:50:46 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_trash(char const *s)
{
	size_t	i;

	i = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		s++;
		i++;
	}
	while (*(s + 1))
		s++;
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		s--;
		i++;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char			*res;
	size_t			len;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) - ft_trash(s);
	if ((res = (char*)malloc(sizeof(char) * len + 1)))
	{
		i = 0;
		while (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		while (i < len)
			res[i++] = *(char*)s++;
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
