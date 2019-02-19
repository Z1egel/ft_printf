/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:39:24 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/26 16:35:36 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_neg_itoa(long long int n)
{
	size_t			len;
	long long int	temp;
	char			*str;

	len = 1;
	temp = n;
	while (n)
	{
		n = n / 10;
		len++;
	}
	if ((str = (char*)malloc(sizeof(char) * len + 1)))
	{
		str[len] = '\0';
		str[0] = '-';
		while (--len)
		{
			str[len] = -1 * (temp % 10) + '0';
			temp = temp / 10;
		}
		return (str);
	}
	return (NULL);
}

static char	*ft_pos_itoa(long long int n)
{
	size_t			len;
	long long int	temp;
	char			*str;

	len = 0;
	temp = n;
	while (n)
	{
		n = n / 10;
		len++;
	}
	if ((str = (char*)malloc(sizeof(char) * len + 1)))
	{
		str[len] = '\0';
		while (--len + 1)
		{
			str[len] = temp % 10 + '0';
			temp = temp / 10;
		}
		return (str);
	}
	return (NULL);
}

static char	*ft_zero_itoa(void)
{
	char	*str;

	if ((str = (char*)malloc(sizeof(char) + 1)))
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	return (NULL);
}

char		*ft_itoa(long long int n)
{
	char	*str;

	if (n < 0)
		str = ft_neg_itoa(n);
	if (n > 0)
		str = ft_pos_itoa(n);
	if (n == 0)
		str = ft_zero_itoa();
	return (str);
}
