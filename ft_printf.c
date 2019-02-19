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

char    *g_base = "0123456789abcdef";
char    *up_g_base = "0123456789ABCDEF";
int     return_length;

void    print_u(long long int nmb, t_flags *flags)
{
    int     spaces;

    if (nmb == 0 && flags->precision == 0)
        return ;
    print_flags(nmb, &spaces, flags);
    print_dec(nmb);
    if (flags->minus)
        print_spaces(spaces);
}

void    print_d(long long int nmb, t_flags *flags)
{
    int     spaces;

    if (nmb == 0 && flags->precision == 0)
        return ;
    if (nmb == 0)
    {
        ft_putstr("+0");
        return_length += 2;
        return ;
    }
    print_flags(nmb, &spaces, flags);
    print_dec(nmb);
    if (flags->minus)
        print_spaces(spaces);
}

void    print_x(long long int nmb, t_flags *flags, char tmp)
{
    int     spaces;

    if (nmb == 0 && flags->precision == 0)
        return ;
    if (nmb == 0)
    {
        ft_putchar('0');
        return_length++;
        return ;
    }
    print_nondec_flags(nmb, &spaces, flags, tmp);
    if (tmp == 'x')
        ft_printnbr_base(nmb, 16, g_base);
    if (tmp == 'X')
        ft_printnbr_base(nmb, 16, up_g_base);
    if (flags->minus)
        print_spaces(spaces);
}

void    print_o(long long int nmb, t_flags *flags)
{
    int     spaces;

    if (nmb == 0 && flags->precision == 0)
        return ;
    if (nmb == 0)
    {
        ft_putchar('0');
        return_length++;
        return ;
    }
    print_nondec_flags(nmb, &spaces, flags, 'o');
    ft_printnbr_base(nmb, 8, g_base);
    if (flags->minus)
        print_spaces(spaces);
}

void    print_s(char *str, t_flags flags)
{
    size_t  len;
    size_t  tmp;
    size_t  str_len;

    if (str == NULL)
    {
        ft_putstr("(null)");
        return_length += 6;
        return ;
    }
    str_len = ft_strlen(str);
    len = ((flags.precision != -1) ? (flags.precision) : (str_len));
    if (!flags.minus)
        print_spaces((len < str_len) ? (flags.width - len) : (flags.width - str_len));
    tmp = len;
    while ((len == 0) ? (0) : (len && *str))
    {
        write(1, str++, 1);
        len--;
        return_length++;
    }
    if (flags.minus)
        print_spaces((tmp < str_len) ? (flags.width - tmp) : (flags.width - str_len));
}

int     check_formats(char **str, va_list *ap)
{
    static t_flags  flags;
    char            tmp;

    set_flags(str, &flags);
    set_width_precision(str, &flags);
    set_modifiers(str, &flags);
    if (**str == 'd' || **str =='i')
    {
        cast_d(&*ap, &flags);
        (*str)++;
        return (0);
    }
    if (**str == 'u')
    {
        cast_u(&*ap, &flags);
        (*str)++;
        return (0);
    }
    if (**str == 'x' || **str =='X')
    {
        tmp = **str;
        cast_x(&*ap, &flags, tmp);
        (*str)++;
        return (0);
    }
    if (**str == 'o')
    {
        cast_o(&*ap, &flags);
        (*str)++;
        return (0);
    }
    if (**str == 'c')
    {
        print_c((char)va_arg(*ap, int), flags);
        return_length++;
        (*str)++;
        return (0);
    }
    if (**str == 's')
    {
        print_s(va_arg(*ap, char *), flags);
        (*str)++;
        return (0);
    }
    if (**str == 'p')
    {
        print_p(va_arg(*ap, void *), &flags);
        (*str)++;
        return (0);
    }
    if (!flags.minus)
    {
        print_spaces(flags.width - 1);
        ft_putchar(**str);
        (*str)++;
        return_length++;
        return (0);
    }
    else
    {
        ft_putchar(**str);
        print_spaces(flags.width - 1);
        (*str)++;
        return_length++;
        return (0);
    }
    return (0);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list		ap;
	char		*input;

	input = ft_strdup(format);
	va_start(ap, format);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
		    check_formats(&input, &ap);
		    continue ;
		}
		if (*input)
		{
            ft_putchar(*input);
            input++;
            return_length++;
        }
	}
	va_end(ap);
	return (return_length);
}