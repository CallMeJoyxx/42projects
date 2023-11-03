/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:54:25 by jtriscar          #+#    #+#             */
/*   Updated: 2023/11/02 23:18:56 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int	count_hex_len_down(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
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

	len = count_hex_len_down(num);
	hexchars = "0123456789abcdef";
	i = len - 1;
	hexstring[len] = '\0';
	while (i >= 0)
	{
		hexstring[i] = hexchars[num % 16];
		num /= 16;
		i--;
	}
}

int	ft_print_hex_down(unsigned long num)
{
	int		len;
	char	*format;

	len = count_hex_len_down(num);
	format = (char *)malloc(len + 1);
	if (format == NULL)
		return (-1);
	if (num == 0)
	{
		format[0] = '0';
		format[1] = '\0';
	}
	else
	{
		convert_to_down(num, format);
	}
	write(1, format, len);
	free(format);
	return (len);
}
