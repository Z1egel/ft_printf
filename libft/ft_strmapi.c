/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:47:24 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/26 15:26:01 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;
	char			*temp;

	if (s == NULL)
		return (NULL);
	i = 0;
	if ((res = (char*)malloc(sizeof(*s) * ft_strlen(s) + 1)))
	{
		temp = res;
		while (*s)
			*temp++ = f(i++, *(char*)s++);
		*temp = '\0';
		return (res);
	}
	return (NULL);
}
