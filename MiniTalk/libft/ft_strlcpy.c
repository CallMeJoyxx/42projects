/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:16:50 by jtriscar          #+#    #+#             */
/*   Updated: 2023/11/12 01:20:01 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned long size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	dest_len = 0;
	src_len = 0;
	i = 0;
	if (!size)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (dest_len < size - 1 && src[src_len])
	{
		dest[dest_len] = src[src_len];
		dest_len++;
		src_len++;
	}
	if (size > i)
		dest[dest_len] = '\0';
	src_len = 0;
	while (src[src_len])
		src_len++;
	return (src_len);
}
