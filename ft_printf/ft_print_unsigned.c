/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 00:00:35 by jtriscar          #+#    #+#             */
/*   Updated: 2023/10/30 21:55:46 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	print_digit(unsigned int num)
{
	int	num_bytes;

	num_bytes = 0;
	if (num >= 10)
	{
		num_bytes += print_digit(num / 10);
	}
	num_bytes += ft_putchar('0' + (num % 10));
	return (num_bytes);
}

int	ft_print_unsigned(unsigned int num)
{
	if (num == 0)
	{
		return (ft_putchar('0'));
	}
	else
	{
		return (print_digit(num));
	}
}
