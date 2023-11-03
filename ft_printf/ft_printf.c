/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:55:11 by jtriscar          #+#    #+#             */
/*   Updated: 2023/11/02 23:06:01 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	handle_format(const char *input, va_list args)

{
	int		i;

	i = 0;
	if (*input == 'c')
		i += ft_print_char(va_arg(args, int));
	else if (*input == 's')
		i += ft_print_string(va_arg(args, char *));
	else if (*input == 'p')
		i += ft_print_ptr(va_arg(args, unsigned long));
	else if (*input == 'i' || *input == 'd')
		i += ft_print_int(va_arg(args, int));
	else if (*input == 'u')
		i += ft_print_unsigned(va_arg(args, unsigned int));
	else if (*input == 'X')
		i += ft_print_hex_up(va_arg(args, unsigned long));
	else if (*input == 'x')
		i += ft_print_hex_down(va_arg(args, unsigned long));
	else if (*input == '%')
		i += write(1, &("%"), 1);
	return (i);
}

static int	ft_check_format(const char *input, va_list args)
{
	int		i;

	i = 0;
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			i += handle_format(input, args);
		}
		else
		{
			if (write(1, input, 1) == -1)
			{
				return (-1);
			}
			i++;
		}
		input++;
	}
	return (i);
}

int	ft_printf(const char *input, ...)
{
	int			result;

	va_list (args);
	va_start (args, input);
	result = ft_check_format(input, args);
	va_end (args);
	return (result);
}
