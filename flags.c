/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 10:44:41 by mbennis           #+#    #+#             */
/*   Updated: 2019/01/12 10:44:43 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

extern int     return_length;

void    set_flags(char **str, t_flags *flags)
{
    while (**str == '#' || **str == '0' || **str == '-' || **str == '+'
           || **str == ' ')
    {
        flags->hash = (**str != '#' && flags->hash != 1) ? (0) : (1);
        flags->minus = (**str != '-' && flags->minus != 1) ? (0) : (1);
        flags->space = (**str != ' ' && flags->space != 1) ? (0) : (1);
        flags->plus = (**str != '+' && flags->plus != 1) ? (0) : (1);
        flags->zero = (**str != '0' && flags->zero != 1) ? (0) : (1);
        (*str)++;
    }
    flags->precision = -1;
    flags->width = -1;
    if (flags->minus && flags->zero)
        flags->zero = 0;
    if (flags->plus && flags->space)
        flags->space = 0;
}

void    set_width_precision(char **str, t_flags *flags)
{
    if (**str > '0' && **str <= '9')
    {
        flags->width = ft_atoi(*str);
        *str = (*str) + ft_strlen(ft_itoa(flags->width));
    }
    if (**str == '.')
        (*str)++;
    if (**str >= '0' && **str <= '9')
    {
        flags->precision = ft_atoi(*str);
        *str = (*str) + ft_strlen(ft_itoa(flags->precision));
    }
}

void    set_modifiers(char **str, t_flags *flags)
{
    while (**str == 'l' || **str == 'h' || **str == 'j' || **str == 'z')
    {
        if (**str == 'l' && *(*str + 1) == 'l')
        {
            flags->ll = 1;
            (*str)++;
        }
        if (**str == 'h' && *(*str + 1) == 'h')
        {
            flags->hh = 1;
            (*str)++;
        }
        flags->z = (**str != 'z' && flags->z != 1) ? (0) : (1);
        flags->j = (**str != 'j' && flags->j != 1) ? (0) : (1);
        flags->l = (**str != 'l' && flags->l != 1) ? (0) : (1);
        flags->h = (**str != 'h' && flags->h != 1) ? (0) : (1);
        (*str)++;
    }
    flags->hh = (flags->h || flags->l || flags->ll || flags->j || flags->z) ? (0) : (flags->hh);
    flags->h = (flags->l || flags->ll || flags->j || flags->z) ? (0) : (flags->h);
    flags->l = (flags->ll || flags->j || flags->z) ? (0) : (flags->l);
    flags->ll = (flags->j || flags->z) ? (0) : (flags->ll);
    flags->j = (flags->z) ? (0) : (flags->j);
}

void    print_flags(long long int nmb, int *spaces, t_flags *flags)
{
    int     nulls;

    nulls = flags->precision - ft_strlen(ft_itoa(nmb)) + ((nmb < 0) ? (1) : (0));
    *spaces = flags->width - ft_strlen(ft_itoa(nmb)) - ((nulls > 0) ? (nulls) : (0)) - ((flags->plus && nmb > 0) ? (1) : (0)) - ((flags->space && nmb > 0) ? (1) : (0));
    if (flags->space && nmb > 0)
    {
        ft_putchar(' ');
        return_length++;
    }
    if (flags->plus && nmb > 0 && flags->minus)
    {
        ft_putchar('+');
        return_length++;
    }
    if (flags->zero && flags->precision == -1)
    {
        print_nulls(*spaces);
        *spaces = 0;
    }
    if (!flags->minus)
        print_spaces(*spaces);
    if (flags->plus && nmb > 0 && !flags->minus)
    {
        ft_putchar('+');
        return_length++;
    }
    if (nmb < 0)
    {
        ft_putchar('-');
        return_length++;
    }
    print_nulls(nulls);
}

void    print_nondec_flags(long long int nmb, int *spaces, t_flags *flags, char tmp)
{
    int     nulls;

    nulls = flags->precision - ft_strlen(ft_itoa(nmb)) + ((nmb < 0) ? (1) : (0)) - ((flags->hash) ? (2) : (0));
    *spaces = flags->width - ft_strlen(ft_itoa(nmb)) - ((nulls > 0) ? (nulls) : (0)) - ((flags->plus && nmb > 0) ? (1) : (0)) - ((flags->space && nmb > 0) ? (1) : (0)) - ((flags->hash) ? (2) : (0));
    if (flags->space && nmb > 0)
    {
        ft_putchar(' ');
        return_length++;
    }
    if (flags->plus && nmb > 0 && flags->minus)
    {
        ft_putchar('+');
        return_length++;
    }
    if (!flags->minus && !flags->zero)
        print_spaces(*spaces);
    if (flags->plus && nmb > 0 && !flags->minus)
    {
        ft_putchar('+');
        return_length++;
    }
    if (flags->hash && (tmp == 'x' || tmp == 'X'))
    {
        ft_putstr((tmp == 'x') ? ("0x") : ("0X"));
        return_length += 2;
    }
    if (flags->zero && flags->precision == -1)
    {
        print_nulls(*spaces);
        *spaces = 0;
    }
    print_nulls(nulls);
}