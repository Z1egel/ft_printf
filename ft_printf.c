/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 20:30:19 by mbennis           #+#    #+#             */
/*   Updated: 2018/12/24 20:30:22 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

char *g_base = "0123456789abcdef";

void    print_d(long long int nmb, t_flags *flags)
{
    int     spaces;

    if (nmb == 0 && flags->precision == 0)
        return ;
    print_flags(nmb, &spaces, flags);
    print_dec(nmb);
    if (flags->minus)
        print_spaces(spaces);
}

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

void    print_o(unsigned int nmb, t_flags *flags)
{
    int     spaces;

    print_flags(nmb, &spaces, flags);

    print_nmb(nmb, 8, g_base);
    if (flags->minus)
        print_spaces(spaces);
}

void    print_s(char *str, t_flags flags)
{
    size_t  len;
    size_t  tmp;
    size_t  str_len;

    str_len = ft_strlen(str);
    len = ((flags.precision != -1) ? (flags.precision) : (str_len));
    if (!flags.minus)
        print_spaces((len < str_len) ? (flags.width - len) : (flags.width - str_len));
    tmp = len;
    while ((len == 0) ? (0) : (len && *str))
    {
        write(1, str++, 1);
        len--;
    }
    if (flags.minus)
        print_spaces((tmp < str_len) ? (flags.width - tmp) : (flags.width - str_len));
}

void	check_formats(char **str, size_t *len, va_list *ap)
{
    static t_flags flags;

    if (**str == '%')
        return ;
    set_flags(str, &flags);
    set_width_precision(str, &flags);
    set_modifiers(str, &flags);
    if (**str == 'd' || **str =='i')
    {
        cast_d(&*ap, &flags);
        (*str)++;
        return ;
    }
    if (**str == 'o')
    {
        print_o((unsigned int)va_arg(*ap, int), &flags);
        (*str)++;
        return ;
    }
    if (**str == 'c')
    {
        print_c((char)va_arg(*ap, int), flags);
        (*str)++;
        return ;
    }
    if (**str == 's')
    {
        print_s(va_arg(*ap, char *), flags);
        (*str)++;
        return ;
    }
    if (**str == 'p')
    {
        print_p(va_arg(*ap, void *), &flags);
        (*str)++;
        return ;
    }
}

int		ft_printf(const char * restrict format, ...)
{
	va_list		ap;
	char		*input;
	size_t 		len;

	len = 0;
	input = ft_strdup(format);
	va_start(ap, format);
	while (*input)
	{
		len++;
		if (*input == '%')
		{
			input++;
		    check_formats(&input, &len, &ap);
		}
		if (*input)
		{
            ft_putchar(*input);
            input++;
        }
	}
	va_end(ap);
	return ((int)len);
}