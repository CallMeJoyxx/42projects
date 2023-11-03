/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:32:51 by jtriscar          #+#    #+#             */
/*   Updated: 2023/10/29 21:32:51 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

int	count_hex_length(unsigned long num)
{
	int	count;

	count = 0;
	while (num != 0)
	{
		count ++;
		num = num / 16;
	}
	return (count);
}

static void	convert_to_down(unsigned long num, char *hexstring)
{
	const char	*hexchars;
	int			len;
	int			i;

	len = count_hex_length(num);
	hexchars = "0123456789abcdef";
	i = len - 1;
	while (i >= 0)
	{
		hexstring[i] = hexchars[num % 16];
		num /= 16;
		i--;
	}
	hexstring[len] = '\0';
}

int	ft_print_ptr(unsigned long pointer)
{
	char	*hexstring;
	int		count;

	hexstring = (char *)malloc(count_hex_length(pointer) + 3);
	count = 0;
	if (hexstring == NULL)
	{
		return (-1);
	}
	count += write(1, "0x", 2);
	convert_to_down(pointer, hexstring);
	count += write(1, hexstring, ft_strlen(hexstring));
	free(hexstring);
	if (pointer == 0)
		count += ft_print_char('0');
	return (count);
}
