/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:55:07 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/21 18:16:31 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*res;

	res = s1;
	while (*res)
		res++;
	while (n-- && *s2)
		*res++ = *(char*)s2++;
	*res = '\0';
	return (s1);
}
