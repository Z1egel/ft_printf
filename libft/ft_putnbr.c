/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:03:43 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/22 20:23:32 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printnbr(int n)
{
	if (n >= 10 || n <= -10)
	{
		ft_printnbr(n / 10);
		ft_printnbr(n % 10);
	}
	else
	{
		if (n < 0)
			ft_putchar(-1 * n + '0');
		else
			ft_putchar(n + '0');
	}
}

void		ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	ft_printnbr(n);
}
