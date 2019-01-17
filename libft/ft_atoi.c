/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:26:24 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/23 21:11:38 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		sign;
	int		result;
	int		counter;

	counter = 0;
	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\r'
			|| *str == '\f' || *str == '\n')
		str++;
	if (*str == '-' && *(str + 1) != '+')
	{
		sign = -sign;
		str++;
	}
	if (*str == '+')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		result = result * 10 + *str - '0';
		str++;
		counter++;
	}
	return (result * sign);
}
