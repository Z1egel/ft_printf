/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 20:31:01 by mbennis           #+#    #+#             */
/*   Updated: 2018/12/24 20:33:42 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include <stdint.h>
#include <string.h>

typedef struct  s_flags
{
    unsigned int    hash;
    unsigned int    zero;
    unsigned int    minus;
    unsigned int    space;
    unsigned int    plus;
    unsigned int    l;
    unsigned int    ll;
    unsigned int    h;
    unsigned int    hh;
    unsigned int    j;
    unsigned int    z;
    int             width;
    int             precision;
}               t_flags;

int		ft_printf(const char * restrict format, ...);
void    set_flags(char **str, t_flags *flags);
void    set_width_precision(char **str, t_flags *flags);
void    set_modifiers(char **str, t_flags *flags);
void    print_flags(long long int nmb, int *spaces, t_flags *flags);
void    print_nondec_flags(long long int nmb, int *spaces, t_flags *flags, char tmp);
void    print_nulls(int n);
void    print_spaces(int n);
void	print_dec(long long int nmb);
void    print_nmb(long long int nmb, int base, char *g_base);
void	cast_d(va_list *ap, t_flags *flags);
void	cast_x(va_list *ap, t_flags *flags, char tmp);
void	cast_o(va_list *ap, t_flags *flags);
void	cast_u(va_list *ap, t_flags *flags);
void    print_o(long long int nmb, t_flags *flags);
void    print_d(long long int nmb, t_flags *flags);
void    print_x(long long int nmb, t_flags *flags, char tmp);
void    print_p(void *ptr, t_flags *flags);
void    print_c(char c, t_flags flags);
void    print_u(long long int nmb, t_flags *flags);
void    ft_putnbr_base(long long int nmb, char *base);
void    ft_printnbr_base(long int nmb, size_t len, char *base);


#endif