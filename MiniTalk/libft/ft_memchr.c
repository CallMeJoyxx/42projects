/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:13:30 by jtriscar          #+#    #+#             */
/*   Updated: 2023/10/12 18:17:09 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, unsigned long n)
{
	unsigned char	*p;
	unsigned char	i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
		{
			return ((void *)(p + i));
		}
		i++;
	}
	return ((void *) 0);
}
