/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:20:09 by mbennis           #+#    #+#             */
/*   Updated: 2019/01/13 18:20:10 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

void    print_c(char c, t_flags flags)
{
    if (!flags.minus)
        print_spaces(flags.width - 1);
    write(1, &c, 1);
    if (flags.minus)
        print_spaces(flags.width - 1);
}