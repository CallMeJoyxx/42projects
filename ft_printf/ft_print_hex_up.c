/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:27:10 by jtriscar          #+#    #+#             */
/*   Updated: 2023/11/02 23:16:18 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int	count_hex_len_up(unsigned int num)
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

static void	convert_to_up(unsigned int num, char *hexstring)
{
	const char	*hexchars;
	int			len;
	int			i;

	len = count_hex_len_up(num);
	hexchars = "0123456789ABCDEF";
	i = len - 1;
	hexstring[len] = '\0';
	while (i >= 0)
	{
		hexstring[i] = hexchars[num % 16];
		num /= 16;
		i--;
	}
}

int	ft_print_hex_up(unsigned long num)
{
	int		len;
	char	*format;

	len = count_hex_len_up(num);
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
		convert_to_up(num, format);
	}
	write(1, format, len);
	free(format);
	return (len);
}
