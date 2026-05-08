/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:25:22 by cagirdem          #+#    #+#             */
/*   Updated: 2022/01/20 14:31:18 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

# define DECIMAL_BASE "0123456789"
# define HEXADECIMAL_U_BASE "0123456789ABCDEF"
# define HEXADECIMAL_L_BASE "0123456789abcdef"

int				ft_printf(const char *format, ...);
int				ft_char_format(char c);
int				ft_string_format(char *str);
int				ft_pointer_format(void *ptr_addr);
int				ft_decimal_format(int value);
int				ft_unsigned_decimal_format(unsigned int value);
int				ft_hexadecimal_format(unsigned int value);
int				ft_upper_case_hexadecimal_format(unsigned int value);
int				ft_percent_format(char c);

#endif
