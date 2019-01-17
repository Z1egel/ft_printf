/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:44:49 by mbennis           #+#    #+#             */
/*   Updated: 2019/01/13 15:44:50 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

int     get_length(long long int nmb, char *base)
{
    size_t  len;
    int     result;

    len = ft_strlen(base);
    result = 0;
    while (nmb)
    {
        nmb = nmb / len;
        result++;
    }
    return (result);
}

void    print_p(void *ptr, t_flags *flags)
{
    long long int   nmb;
    int             spaces;
    int             nulls;
    int             len;

    nmb = (long long int)ptr;
    len = get_length(nmb, "0123456789abcdef");
    nulls = flags->precision - len;
    spaces = flags->width - ((nulls > 0) ? (nulls) : (0)) - len - 2;
    if (!flags->minus)
        print_spaces(spaces);
    ft_putstr("0x");
    print_nulls(nulls);
    ft_putnbr_base(nmb, "0123456789abcdef");
    if (flags->minus)
        print_spaces(spaces);
}