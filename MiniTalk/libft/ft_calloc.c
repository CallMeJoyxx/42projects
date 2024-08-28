/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:43:22 by jtriscar          #+#    #+#             */
/*   Updated: 2023/10/18 21:45:08 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(unsigned long count, unsigned long size)
{
	void			*np;
	unsigned long	total;

	total = count * size;
	np = malloc(total);
	if (!np)
		return (NULL);
	ft_memset(np, 0, total);
	return (np);
}
