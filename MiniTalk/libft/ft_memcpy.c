/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:28:22 by jtriscar          #+#    #+#             */
/*   Updated: 2023/10/12 20:43:45 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, unsigned long n)
{
	unsigned long		i;
	char				*d;
	char				*s;

	d = (char *)dest;
	s = (char *)src;
	i = 0;
	if (dest == (void *)0 && src == (void *)0)
		return ((void *)0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
