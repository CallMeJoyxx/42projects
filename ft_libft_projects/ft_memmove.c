/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:29:14 by jtriscar          #+#    #+#             */
/*   Updated: 2023/10/13 18:02:10 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, unsigned long len)
{
	char				*d;
	char				*s;

	d = (char *)dest;
	s = (char *)src;
	if (dest == (void *)0 && src == (void *)0)
		return ((void *)0);
	if (d < s)
	{
		while (len-- > 0)
			*d++ = *s++;
	}
	else if (d > s)
	{
		d += len;
		s += len;
		while (len-- > 0)
			*(--d) = *(--s);
	}
	else
	{
		return (dest);
	}
	return (dest);
}
