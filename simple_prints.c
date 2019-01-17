/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_prints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 10:53:23 by mbennis           #+#    #+#             */
/*   Updated: 2019/01/12 10:53:25 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

void    print_nulls(int n)
{
     if (n > 0)
    {
        while (n)
        {
            ft_putchar('0');
            n--;
        }
    }
}

void    print_spaces(int n)
{
    if (n > 0)
    {
        while (n)
        {
            ft_putchar(' ');
            n--;
        }
    }
}

void    ft_printnbr_base(long long int nmb, size_t len, char *base)
{
    if (nmb)
    {
        ft_printnbr_base(nmb / len, len, base);
        ft_putchar(base[nmb % len]);
    }
}

void    ft_putnbr_base(long long int nmb, char *base)
{
    size_t  len;

    len = ft_strlen(base);
    ft_printnbr_base(nmb, len, base);
}

void	print_dec(long long int nmb)
{
    if (nmb >= 10 || nmb <= -10)
    {
        print_dec(nmb / 10);
        print_dec(nmb % 10);
    }
    else
    {
        if (nmb < 0)
            ft_putchar(-1 * nmb + '0');
        else
            ft_putchar(nmb + '0');
    }
}

void    print_nmb(long long int nmb, int base, char *g_base)
{
    if (nmb)
    {
        print_nmb(nmb / base, base, g_base);
        ft_putchar(g_base[nmb % base]);
    }
}