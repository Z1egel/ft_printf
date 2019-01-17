/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:41:00 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/25 17:26:47 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmp_needle_substr(const char *needle, char *substring)
{
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

char		*ft_strstr(const char *haystack, const char *needle)
{
	char	*substring;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack)
	{
		if (*haystack != *needle)
			haystack++;
		else
		{
			substring = (char*)haystack;
			if (ft_cmp_needle_substr(needle, substring))
				return (substring);
			else
				haystack++;
		}
	}
	return (NULL);
}
