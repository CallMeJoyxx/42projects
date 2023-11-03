/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:32:51 by jtriscar          #+#    #+#             */
/*   Updated: 2023/11/02 22:03:13 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	count_digits(int n)
{
	int	digits;
	int	num;

	num = n;
	digits = 1;
	if (n < 0)
	{
		num = -n;
	}
	while (num >= 10)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

void	print_num(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		print_num(n / 10);
	}
	ft_putchar(n % 10 + '0');
}

int	ft_print_int(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n == 2147483647)
	{
		write(1, "2147483647", 10);
		return (10);
	}
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	i = count_digits(n);
	print_num(n);
	if (n < 0)
		return (i + 1);
	else
		return (i);
}
