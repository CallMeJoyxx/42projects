/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:27:56 by jtriscar          #+#    #+#             */
/*   Updated: 2023/10/21 22:11:08 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	unsigned long	len;
	unsigned long	i;
	char			*cpy;

	len = 0;
	while (s1[len] != '\0')
	{
		len++;
	}
	cpy = (char *)malloc(len + 1);
	if (cpy == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[len] = '\0';
	return (cpy);
}
