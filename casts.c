/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:48:59 by mbennis           #+#    #+#             */
/*   Updated: 2019/02/11 10:49:00 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

void	cast_d(va_list *ap, t_flags *flags)
{
    if (flags->hh)
    {
        print_d((char)va_arg(*ap, int), flags);
        return ;
    }
    if (flags->h)
    {
        print_d((short int)va_arg(*ap, int), flags);
        return ;
    }
    if (flags->l)
    {
        print_d(va_arg(*ap, long int), flags);
        return ;
    }
    if (flags->ll)
    {
        print_d(va_arg(*ap, long long int), flags);
        return ;
    }
    print_d(va_arg(*ap, int), flags);
}

void	cast_u(va_list *ap, t_flags *flags)
{
    if (flags->hh)
    {
        print_u((char)va_arg(*ap, int), flags);
        return ;
    }
    if (flags->h)
    {
        print_u((short int)va_arg(*ap, int), flags);
        return ;
    }
    if (flags->l)
    {
        print_u(va_arg(*ap, long int), flags);
        return ;
    }
    if (flags->ll)
    {
        print_u(va_arg(*ap, long long int), flags);
        return ;
    }
    print_d(va_arg(*ap, unsigned int), flags);
}

void	cast_x(va_list *ap, t_flags *flags, char tmp)
{
    if (flags->hh)
    {
        print_x((char)va_arg(*ap, int), flags, tmp);
        return ;
    }
    if (flags->h)
    {
        print_x((short int)va_arg(*ap, int), flags, tmp);
        return ;
    }
    if (flags->l)
    {
        print_x(va_arg(*ap, long int), flags, tmp);
        return ;
    }
    if (flags->ll)
    {
        print_x(va_arg(*ap, long long int), flags, tmp);
        return ;
    }
    if (flags->j)
    {
        print_x(va_arg(*ap, long long int), flags, tmp);
        return ;
    }
    print_x(va_arg(*ap, unsigned int), flags, tmp);
}

void	cast_o(va_list *ap, t_flags *flags)
{
    if (flags->hh)
    {
        print_o((char)va_arg(*ap, int), flags);
        return ;
    }
    if (flags->h)
    {
        print_o((short int)va_arg(*ap, int), flags);
        return ;
    }
    if (flags->l)
    {
        print_o(va_arg(*ap, long int), flags);
        return ;
    }
    if (flags->ll)
    {
        print_o(va_arg(*ap, long long int), flags);
        return ;
    }
    if (flags->j)
    {
        print_o(va_arg(*ap, long long int), flags);
        return ;
    }
    print_o(va_arg(*ap, unsigned int), flags);
}