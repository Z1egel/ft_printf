/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:27:31 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/26 15:25:26 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	char	*temp;

	if (s == NULL)
		return (NULL);
	if ((res = (char*)malloc(sizeof(*s) * ft_strlen(s) + 1)))
	{
		temp = res;
		while (*s)
			*temp++ = f(*(char*)s++);
		*temp = '\0';
		return (res);
	}
	return (NULL);
}
