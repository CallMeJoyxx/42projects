/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 23:21:08 by jtriscar          #+#    #+#             */
/*   Updated: 2023/11/10 21:10:55 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_print_string(const char *string)
{
	int	char_count;

	char_count = 0;
	if (string == NULL)
	{
		if (write(1, "(null)", 6) == -1)
		{
			return (-1);
		}
		char_count = 6;
	}
	else
	{
		while (*string)
		{
			if (write(1, string, 1) == -1)
			{
				return (-1);
			}
			string++;
			char_count++;
		}
	}
	return (char_count);
}
