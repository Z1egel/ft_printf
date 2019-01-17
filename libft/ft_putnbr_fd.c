/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:17:49 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/26 14:48:09 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printnbr_fd(int n, int fd)
{
	if (n >= 10 || n <= -10)
	{
		ft_printnbr_fd(n / 10, fd);
		ft_printnbr_fd(n % 10, fd);
	}
	else
	{
		if (n < 0)
			ft_putchar_fd(-1 * n + '0', fd);
		else
			ft_putchar_fd(n + '0', fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_printnbr_fd(n, fd);
}
