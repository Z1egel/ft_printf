/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:28:06 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/24 06:09:46 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	char	*temp;

	if ((str = (char*)malloc(sizeof(char) * (size + 1))))
	{
		temp = str;
		while (size--)
			*temp++ = '\0';
		*temp = '\0';
		return (str);
	}
	return (NULL);
}
