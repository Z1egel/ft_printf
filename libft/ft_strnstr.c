/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:48:05 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/25 18:06:42 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	ft_cmp_needle_substr(const char *needle, char *substring, size_t t)
{
	if (ft_strlen(needle) > t)
		return (0);
	while (*needle)
	{
		if (*(char*)needle == *substring)
		{
			if (*(char*)(needle + 1) == '\0')
				return (1);
			needle++;
			substring++;
		}
		else
			return (0);
	}
	return (2);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*substring;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack && len)
	{
		if (*haystack != *needle)
		{
			haystack++;
			len--;
		}
		else
		{
			substring = (char*)haystack;
			if (ft_cmp_needle_substr(needle, substring, len))
				return (substring);
			else
				haystack++;
		}
	}
	return (NULL);
}
