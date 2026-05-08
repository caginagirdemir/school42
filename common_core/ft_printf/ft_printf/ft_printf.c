/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:09:36 by cagirdem          #+#    #+#             */
/*   Updated: 2022/01/20 15:35:50 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(int c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_char_format(va_arg(args, int));
	else if (c == 's')
		i = ft_string_format(va_arg(args, char *));
	else if (c == 'p')
		i = ft_pointer_format(va_arg(args, void *));
	else if (c == 'i' || c == 'd')
		i = ft_decimal_format(va_arg(args, int));
	else if (c == 'u')
		i = ft_unsigned_decimal_format(va_arg(args, unsigned long));
	else if (c == 'x')
		i = ft_hexadecimal_format(va_arg(args, unsigned long));
	else if (c == 'X')
		i = ft_upper_case_hexadecimal_format(va_arg(args, unsigned long));
	else if (c == '%')
		i = ft_percent_format(c);
	return (i);
}

int	ft_is_argument(int c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

static int	ft_parser(const char *str, va_list args)
{
	int	pos;
	int	i;

	pos = 0;
	i = 0;
	while (str[pos])
	{
		if (str[pos] != '%')
			i += ft_putchar_fd(str[pos], 1);
		else if ((str[pos] == '%') && str[pos + 1])
		{
			pos++;
			if (ft_is_argument(str[pos]))
				i += ft_formats(str[pos], args);
			else if (str[pos])
				i += ft_putchar_fd(str[pos], 1);
		}
		pos++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	const char	*str;
	int			i;

	i = 0;
	str = ft_strdup(format);
	if (!str)
		return (0);
	va_start(args, format);
	i += ft_parser(str, args);
	va_end(args);
	free((void *)str);
	return (i);
}
