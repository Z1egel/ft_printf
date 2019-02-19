/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 20:44:24 by mbennis           #+#    #+#             */
/*   Updated: 2018/12/24 20:44:26 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <stdio.h>

int 	main(void)
{
    printf("%d\n", printf("%lu\n", -42));
    ft_printf("%d", ft_printf("%lu\n", -42));
	return (0);
}